# Lines added by author

class FileSystemWrapper

  def cd(path)
    FileUtils.cd path do
      yield
    end
  end

end
