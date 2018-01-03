#ifndef XWALLPAPERFACTORY_H
#define XWALLPAPERFACTORY_H

#include <atomic>
#include <Imlib2.h>

#include "../Factory.h"
#include "../../wallpaper/X11/XWallpaperImage.h"
#include "../../display/X11/XWallpaperDisplay.h"

#define MEMORY_SIZE 4

class XFactory : public Factory {
private:
    static std::atomic_bool imlibInitialized;
public:

    XFactory();
    WallpaperImage* createWallpaper(const std::string & imgPath);
    WallpaperDisplay* createDisplay();
};

#endif /* XWALLPAPERFACTORY_H */

