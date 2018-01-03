#ifndef XDISPLAY_H
#define XDISPLAY_H

#include <memory>
#include <Imlib2.h>
#include <X11/Xlib.h>

#include "../WallpaperDisplay.h"
#include "../../wallpaper/X11/XWallpaperImage.h"

class XWallpaperDisplay : public WallpaperDisplay {
    // Variables
private:
    Display *display;
    Screen *screen;
    Window window;
    int depth;

    // Methods
public:
    XWallpaperDisplay();
    ~XWallpaperDisplay();
    void renderImage(WallpaperImage *image, const int & x = 0, const int & y = 0);
private:
    int getDefaultScreen();
};

#endif /* XDISPLAY_H */

