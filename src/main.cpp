#include <iostream>
#include <string>

#include "factory/Factory.h"
#include "factory/X11/XFactory.h"
#include "display/WallpaperDisplay.h"
#include "wallpaper/WallpaperImage.h"
#include "FileManager.h"

using namespace std;

void printHelp() {
    cout << "Arguments of application:\n";
    cout << "-h - show this help\n\n"; // FIXME - implement
    cout << "Example how to use this application:\n";
    cout << "swallpaper [path-to-image] [path-to-images...] [path-to-directory]" << endl;
}

set<string> processArguments(const int &argc, char const* const*argv) {
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

void displayImages(Factory *factory, const set<string> &imagePaths) {
    WallpaperDisplay *display = factory->createDisplay();

    for (auto imagePath : imagePaths) {
        WallpaperImage *image = factory->createWallpaper(imagePath);
        display->renderImage(image);
        delete image;
    }
}

int main(int argc, char const* argv[]) {
    FileManager fileManager = FileManager(processArguments(argc, argv));
    displayImages(new XFactory(), fileManager.getImagePaths());
}