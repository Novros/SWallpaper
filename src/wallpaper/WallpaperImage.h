#ifndef WALLPAPERIMAGE_H
#define WALLPAPERIMAGE_H

#define UNDEFINED_SIZE -1

class WallpaperImage {
    // Variables
protected:
    int width = 0;
    int height = 0;

    // Methods
public:
    virtual ~WallpaperImage() = default;
};

#endif /* WALLPAPERIMAGE_H */

