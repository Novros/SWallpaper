#ifndef WALLPAPERMANAGER_H
#define WALLPAPERMANAGER_H

#include <list>
#include <chrono>
#include <thread>

#include "../display/WallpaperDisplay.h"
#include "../wallpaper/WallpaperImage.h"

#define DEFAULT_DELAY 1000;

class WallpaperManager {
    // Delay between each wallpaper image in milis.
    int wallpaperDelay = DEFAULT_DELAY;

    // Show wallpaper on this display.
    WallpaperDisplay* display;

    // Images which will be showed on display.
    std::list<WallpaperImage*> images;

    // Flag to stop this manager running.
    bool running = true;
public:

    WallpaperManager(WallpaperDisplay* display, const std::list<WallpaperImage*> &images) {
        this->display = display;
        this->images = images;
    }

    ~WallpaperManager() {
        for (auto img : images) {
            delete img;
        }
        images.clear();

        delete display;
    }

    inline void setWallpaperDelay(const int &delay) {
        wallpaperDelay = delay;
    }

    void run() const;

    void stop() {
        running = false;
    }
private:
    void setWallpaperOnce() const;
    void changeWallpapers() const;
};

#endif /* WALLPAPERMANAGER_H */

