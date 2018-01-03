#include "XFactory.h"

std::atomic_bool XFactory::imlibInitialized = {false};

XFactory::XFactory() {
    if (!imlibInitialized) {
        imlib_set_cache_size(MEMORY_SIZE * 1024 * 1024);
        imlibInitialized = {true};
    }
}

WallpaperImage* XFactory::createWallpaper(const std::string & imgPath){
    return new XWallpaperImage(imgPath);
}

WallpaperDisplay* XFactory::createDisplay(){
    return new XWallpaperDisplay();
}