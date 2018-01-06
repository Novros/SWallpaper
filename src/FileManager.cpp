#include "FileManager.h"

FileManager::FileManager(const set<string> &paths) {
    initializeSupportedImages();
    processPaths(paths);
}

void FileManager::initializeSupportedImages() {
    supportedImages = set<string>();
    char imageTypes[] = SUPPORTED_IMAGES;
    char* type = strtok(imageTypes, SUPPORTED_IMAGES_DELIMITER);
    while (type != nullptr) {
        supportedImages.insert(type);
        type = strtok(NULL, SUPPORTED_IMAGES_DELIMITER);
    }
}

void FileManager::processPaths(const set<string> &paths) {
    for (auto path : paths) {
        if (isDirectory(path)) {
            processPaths(getPathsFromDirectory(path));
        } else if (isFile(path) && isSupportedImage(path)) {
            imagePaths.insert(path);
        }
    }
}

set<string> FileManager::getPathsFromDirectory(const string &path) {
    set<string> files = set<string>();
    DIR *directory = opendir(path.c_str());

    if (directory != nullptr) {
        struct dirent *file;
        while ((file = readdir(directory)) != nullptr) {
            string fileName = string(file->d_name);
            if (fileName.compare(".") != 0 && fileName.compare("..") != 0) {
                files.insert(path + fileName); // FIXME Not crossplatform.
            }
        }
        closedir(directory);
    }

    return files;
}

bool FileManager::isDirectory(const string &path) {
    // FIXME - beware, not multiplatform, this is using posix library
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}

bool FileManager::isFile(const string &path) {
    // FIXME - beware, not multiplatform, this is using posix library
    struct stat buf;
    stat(path.c_str(), &buf);
    return S_ISREG(buf.st_mode);
}

bool FileManager::isSupportedImage(const string &path) {
    string fileType = path.substr(path.find_last_of(".") + 1);
    return supportedImages.find(fileType) != supportedImages.end();
}