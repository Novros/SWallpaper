#include "WallpaperManager.h"
#include "../display/WallpaperDisplay.h"

void WallpaperManager::run() const {
    if (images.empty()) {
        // Do nothing
    } else if (images.size() == 1) {
        /* TODO
         * - If gif image play as animation.
         */
        setWallpaperOnce();
    } else {
        changeWallpapers();
    }
}

void WallpaperManager::setWallpaperOnce() const {
    display->renderImage(*images.begin());
}

void WallpaperManager::changeWallpapers() const {
    while (running) {
        for (auto image : images) {
            display->renderImage(image);
            std::this_thread::sleep_for(std::chrono::milliseconds(wallpaperDelay));
        }
    }
}