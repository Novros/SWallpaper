#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<set>
#include<string>
#include<sys/stat.h>

using namespace std;

class FileManager {
    set<string> imagePaths;
public:
    FileManager(const set<string> &paths);

    inline set<string> getImagePaths() const {
        return imagePaths;
    }
private:
    void processPaths(const set<string> &paths);
    set<string> getPathsFromDirectory(const string &path);
    bool isDirectory(const string &path);
    bool isFile(const string &path);
};

#endif /* FILEMANAGER_H */

