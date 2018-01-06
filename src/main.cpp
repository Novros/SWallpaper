#include <iostream>
#include <string>
#include <list>

#include "factory/Factory.h"
#include "factory/X11/XFactory.h"
#include "display/WallpaperDisplay.h"
#include "wallpaper/WallpaperImage.h"
#include "FileManager.h"
#include "WallpaperManager.h"

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
    WallpaperManager manager = createManager(new XFactory(), fileManager.getImagePaths());
    manager.run();
}