#!/usr/bin/env python3
import os
import sys
import argparse
from git import Repo, NULL_TREE

def collect_contributions(repo_path, author_name, author_email):
    repo = Repo(repo_path)
    contribs = {}  # file_path -> list of added-line strings

    # Walk all commits by this author
    for commit in repo.iter_commits(
            author=f"{author_name} <{author_email}>"):
        parent = commit.parents[0] if commit.parents else NULL_TREE
        diffs = commit.diff(parent, create_patch=True, unified=0)
        for d in diffs:
            if d.new_file or d.a_blob and d.b_blob:
                path = d.b_path  # new path
                patch = d.diff.decode('utf-8', errors='ignore').splitlines()
                # grab only lines starting with '+' (but not '+++')
                added = [l[1:] for l in patch
                         if l.startswith('+') and not l.startswith('+++')]
                if not added:
                    continue
                contribs.setdefault(path, []).extend(added)

    return contribs

def write_patch(contribs, out_path):
    """
    Turn each collected added-line into a pseudo-patch hunk.
    """
    with open(out_path, 'w') as f:
        f.write(f"# Consolidated contributions\n")
        for path, lines in contribs.items():
            f.write(f"\n--- {path}\n")
            for ln in lines:
                f.write(f"+{ln}\n")

def main():
    p = argparse.ArgumentParser(
        description="Extract all added lines by one author, across all commits.")
    p.add_argument('repo', help="Path to your git repo")
    p.add_argument('--author-name', required=True)
    p.add_argument('--author-email', required=True)
    p.add_argument('--out-patch',
                   default='author_contributions.patch',
                   help="File to write the consolidated patch")
    args = p.parse_args()

    if not os.path.isdir(os.path.join(args.repo, '.git')):
        print("Error: not a git repo:", args.repo, file=sys.stderr)
        sys.exit(1)

    print("Scanning repository for commits by "
          f"{args.author_name} <{args.author_email}>…")
    contribs = collect_contributions(args.repo,
                                     args.author_name,
                                     args.author_email)

    print(f"Found contributions in {len(contribs)} files.")
    for path, lines in contribs.items():
        print(f"  {path}: {len(lines)} added lines")

    print("Writing consolidated patch to", args.out_patch)
    write_patch(contribs, args.out_patch)
    print("Done.")

if __name__ == '__main__':
    main()
