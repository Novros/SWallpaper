#include <iostream>
#include <list>

#include "factory/Factory.h"
#include "factory/ImlibFactory.h"
#include "manager/FileManager.h"
#include "manager/WallpaperManager.h"

using namespace std;

void printHelp() {
    cout << "Arguments of application:\n";
    cout << "-h - show this help\n\n"; // FIXME - implement
    cout << "Example how to use this application:\n";
    cout << "swallpaper [path-to-image] [path-to-images...] [path-to-directory]" << endl;
}

set<string> processArguments(const int &argc, char const* const*argv) {
    /* TODO Add options
     * - add argument parser
     * - h for help
     * - d - for delay
     * - s - frames per second
     */
    if (argc < 2) {
        cout << "Error: No image/s was given.\n" << endl;
        printHelp();
        exit(1);
    } else {
        set<string> filePaths = set<string>();
        for (int i = 1; i < argc; i++) {
            filePaths.insert(argv[i]);
        }
        return filePaths;
    }
}

WallpaperManager createManager(Factory *factory, const set<string> &imagePaths) {
    WallpaperDisplay *display = factory->createDisplay();

    list<WallpaperImage*> images = list<WallpaperImage*>();
    for (auto imagePath : imagePaths) {
	images.push_back(factory->createWallpaper(imagePath));
    }

    return WallpaperManager(display, images);
}

int main(int argc, char const* argv[]) {
    FileManager fileManager = FileManager(processArguments(argc, argv));
    WallpaperManager manager = createManager(new ImlibFactory(), fileManager.getImagePaths());
    manager.run();
}