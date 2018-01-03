#ifndef WALLPAPERFACTORY_H
#define WALLPAPERFACTORY_H

#include <string>

#include "../display/WallpaperDisplay.h"
#include "../wallpaper/WallpaperImage.h"

class Factory {
public:
    virtual WallpaperDisplay* createDisplay() = 0;
    virtual WallpaperImage* createWallpaper(const std::string & imgPath) = 0;
};

#endif /* WALLPAPERFACTORY_H */

