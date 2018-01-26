#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<set>
#include<string>
#include<cstring>
#include<sys/stat.h>
#include<dirent.h>
#include<iostream>

using namespace std;

#define SUPPORTED_IMAGES "png;jpeg;jpg;gif;bmp"
#define SUPPORTED_IMAGES_DELIMITER ";"

class FileManager {
    set<string> supportedImages;
    set<string> imagePaths;
public:
    FileManager(const set<string> &paths);

    inline set<string> getImagePaths() const {
        return imagePaths;
    }
private:
    void initializeSupportedImages();
    void processPaths(const set<string> &paths);
    set<string> getPathsFromDirectory(const string &path);

    bool isDirectory(const string &path);
    bool isFile(const string &path);
    bool isSupportedImage(const string &path);
};

#endif /* FILEMANAGER_H */

