#ifndef XWALLPAPERIMAGE_H
#define XWALLPAPERIMAGE_H

#include <string>
#include <Imlib2.h>

#include "WallpaperImage.h"

class ImlibWallpaperImage : public WallpaperImage {
    // Variables
private:
    Imlib_Image img = nullptr;
    char antialias = 0;
    char dither = 0;
    char blend = 0;

    // Methods
public:
    ImlibWallpaperImage(const std::string &imgPath);
    ~ImlibWallpaperImage();

    void render(const Drawable &drawable, const int & width = UNDEFINED_SIZE, const int & height = UNDEFINED_SIZE, const int & x = 0, const int & y = 0);

    inline void setBlend(const bool &blend) {
        this->blend = blend ? 1 : 0;
    }

    inline void setAntialias(const bool &antialias) {
        this->antialias = antialias ? 1 : 0;
    }

    inline void setDither(const bool &dither) {
        this->dither = dither ? 1 : 0;
    }
};

#endif /* XWALLPAPERIMAGE_H */

