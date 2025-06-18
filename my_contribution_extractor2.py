#!/usr/bin/env python3
import os
import sys
import argparse
from git import Repo, NULL_TREE

def collect_contributions(repo_path, author_name, author_email):
    repo = Repo(repo_path)
    contribs = {}  # file_path -> list of added-line strings

    for commit in repo.iter_commits(author=f"{author_name} <{author_email}>"):
        parent = commit.parents[0] if commit.parents else NULL_TREE
        diffs = commit.diff(parent, create_patch=True, unified=0)

        for d in diffs:
            # We only care about real files (skip submodules, renames of directories, etc.)
            if not d.b_blob or d.b_blob.type != 'blob':
                continue

            path = d.b_path
            patch_lines = d.diff.decode('utf-8', errors='ignore').splitlines()
            # Grab only lines starting with '+' but not the file-header '+++'
            added = [l[1:] for l in patch_lines
                     if l.startswith('+') and not l.startswith('+++')]

            if not added:
                continue

            contribs.setdefault(path, []).extend(added)

    return contribs

def write_contrib_folders(contribs, output_base):
    for rel_path, lines in contribs.items():
        out_path = os.path.join(output_base, rel_path)
        out_dir = os.path.dirname(out_path)
        os.makedirs(out_dir, exist_ok=True)

        # If somehow out_path is already a directory, skip it
        if os.path.isdir(out_path):
            print(f"Skipping directory (not a file): {out_path}")
            continue

        with open(out_path, 'w') as f:
            f.write("# Lines added by author\n")
            for ln in lines:
                f.write(f"{ln}\n")

def main():
    p = argparse.ArgumentParser(
        description="Extract all added lines by one author into a mirrored folder structure.")
    p.add_argument('repo', help="Path to your git repo")
    p.add_argument('--author-name', required=True,
                   help="Git author name, e.g. \"RayCxggg\"")
    p.add_argument('--author-email', required=True,
                   help="Git author email, e.g. \"chexj18@163.com\"")
    p.add_argument('--out-dir', default='my_contributions',
                   help="Output directory to create (will mirror your repo tree)")
    args = p.parse_args()

    gitdir = os.path.join(args.repo, '.git')
    if not os.path.isdir(gitdir):
        print(f"Error: `{args.repo}` is not a git repository (no {gitdir}).", file=sys.stderr)
        sys.exit(1)

    print(f"Scanning `{args.repo}` for commits by {args.author_name} <{args.author_email}> …")
    contribs = collect_contributions(args.repo, args.author_name, args.author_email)

    if not contribs:
        print("No contributions found for that author.")
        sys.exit(0)

    print(f"Writing contributions into folder: `{args.out_dir}`")
    write_contrib_folders(contribs, args.out_dir)
    print("Done. Your contributions are in:", args.out_dir)

if __name__ == '__main__':
    main()
