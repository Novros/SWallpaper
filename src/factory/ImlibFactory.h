#ifndef XWALLPAPERFACTORY_H
#define XWALLPAPERFACTORY_H

#include <atomic>
#include <Imlib2.h>

#include "Factory.h"
#include "../wallpaper/ImlibWallpaperImage.h"
#include "../display/ImlibWallpaperDisplay.h"

#define MEMORY_SIZE 4

class ImlibFactory : public Factory {
private:
	static std::atomic_bool imlibInitialized;
public:

	ImlibFactory();

	WallpaperImage *createWallpaper(const std::string &imgPath);

	WallpaperDisplay *createDisplay();
};

#endif /* XWALLPAPERFACTORY_H */

