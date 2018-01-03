#ifndef DISPLAY_H
#define DISPLAY_H

#include "../wallpaper/WallpaperImage.h"

class WallpaperDisplay {
public:
    virtual void renderImage(WallpaperImage *image, const int & x = 0, const int & y = 0) = 0;
};

#endif /* DISPLAY_H */

