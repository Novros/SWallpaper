#include "XWallpaperDisplay.h"

XWallpaperDisplay::XWallpaperDisplay() {
    display = XOpenDisplay(NULL);
    screen = ScreenOfDisplay(display, getDefaultScreen());

    imlib_context_set_display(display);
    imlib_context_set_visual(DefaultVisual(display, getDefaultScreen()));
    imlib_context_set_colormap(DefaultColormap(display, getDefaultScreen()));
    imlib_context_set_color_modifier(NULL);
    imlib_context_set_progress_function(NULL);
    imlib_context_set_operation(IMLIB_OP_COPY);

    window = RootWindow(display, getDefaultScreen());
    depth = DefaultDepth(display, getDefaultScreen());
}

XWallpaperDisplay::~XWallpaperDisplay() {
    XSetCloseDownMode(display, RetainPermanent);
    XCloseDisplay(display);
}

void XWallpaperDisplay::renderImage(WallpaperImage *image, const int & x, const int & y) {
    if (XWallpaperImage * xImage = dynamic_cast<XWallpaperImage *> (image)) {
        const Drawable drawable = XCreatePixmap(display, window, screen->width, screen->height, depth);
        xImage->render(drawable, screen->width, screen->height, x, y);

        XSetWindowBackgroundPixmap(display, window, drawable);
        XClearWindow(display, window);
        XFlush(display);
    }
}

int XWallpaperDisplay::getDefaultScreen() {
    return DefaultScreen(display);
}