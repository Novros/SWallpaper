#include "WallpaperManager.h"
#include "display/WallpaperDisplay.h"

void WallpaperManager::run() const {
    while (running) {
        for (auto image : images) {
            display->renderImage(image);
            std::this_thread::sleep_for(std::chrono::milliseconds(wallpaperDelay));
        }
    }
}