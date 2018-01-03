#include <iostream>
#include <string>

#include "factory/Factory.h"
#include "factory/X11/XFactory.h"
#include "display/WallpaperDisplay.h"
#include "wallpaper/WallpaperImage.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "No image was given." << endl;
        exit(1);
    }

    Factory *factory = new XFactory();
    WallpaperDisplay *display = factory->createDisplay();
    WallpaperImage *image = factory->createWallpaper(string(argv[1]));
    display->renderImage(image);
}