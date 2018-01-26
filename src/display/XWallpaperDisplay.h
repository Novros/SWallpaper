#ifndef XWALLPAPERDISPLAY_H
#define XWALLPAPERDISPLAY_H

#include <X11/Xlib.h>

#include "WallpaperDisplay.h"
#include "../wallpaper/ImlibWallpaperImage.h"

class XWallpaperDisplay : public WallpaperDisplay {
    // Variables
private:
    Screen *screen;
    Window window;
    Drawable drawable;
    int depth;

protected:
	Display *display;

    // Methods
public:
    XWallpaperDisplay();
    ~XWallpaperDisplay();
    void renderImage(WallpaperImage *image, const int & x = 0, const int & y = 0);

protected:
    int getDefaultScreen();
};

#endif /* XWALLPAPERDISPLAY_H */

