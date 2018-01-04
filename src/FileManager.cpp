#include "FileManager.h"

FileManager::FileManager(const set<string> &paths) {
    processPaths(paths);
}

void FileManager::processPaths(const set<string> &paths) {
    for (auto path : paths) {
        if (isDirectory(path)) {
	    processPaths(getPathsFromDirectory(path));
        } else if (isFile(path)) {
	    imagePaths.insert(path);
        }
    }
}

set<string> FileManager::getPathsFromDirectory(const string &path) {
    return set<string>(); // TODO: #1 - Add support for directories
}

bool FileManager::isDirectory(const string &path) {
    // FIXME - beware, not multiplatform, use posix library
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}

bool FileManager::isFile(const string &path) {
    // FIXME - beware, not multiplatform, use posix library
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISREG(buf.st_mode);
}