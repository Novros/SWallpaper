#include "ImlibFactory.h"
#include "../display/ImlibWallpaperDisplay.h"

std::atomic_bool ImlibFactory::imlibInitialized = {false};

ImlibFactory::ImlibFactory() {
    if (!imlibInitialized) {
        imlib_set_cache_size(MEMORY_SIZE * 1024 * 1024);
        imlibInitialized = {true};
    }
}

WallpaperImage* ImlibFactory::createWallpaper(const std::string & imgPath){
    return new ImlibWallpaperImage(imgPath);
}

WallpaperDisplay* ImlibFactory::createDisplay(){
    return new ImlibWallpaperDisplay();
}