#include "XWallpaperDisplay.h"

XWallpaperDisplay::XWallpaperDisplay() {
    display = XOpenDisplay(nullptr);
    screen = ScreenOfDisplay(display, getDefaultScreen());
    window = RootWindow(display, getDefaultScreen());
    depth = DefaultDepth(display, getDefaultScreen());
    drawable = XCreatePixmap(display, window, screen->width, screen->height, depth);
    XSetWindowBackgroundPixmap(display, window, drawable);
}

XWallpaperDisplay::~XWallpaperDisplay() {
    XSetCloseDownMode(display, RetainPermanent);
    XCloseDisplay(display);
    delete screen;
    display = nullptr;
    screen = nullptr;
}

void XWallpaperDisplay::renderImage(WallpaperImage *image, const int & x, const int & y) {
    if (auto * xImage = dynamic_cast<ImlibWallpaperImage *> (image)) {
        xImage->render(drawable, screen->width, screen->height, x, y);
        XClearWindow(display, window);
        XFlush(display);
    }
}

int XWallpaperDisplay::getDefaultScreen() {
    return DefaultScreen(display);
}