#include "ImlibWallpaperDisplay.h"

ImlibWallpaperDisplay::ImlibWallpaperDisplay() : XWallpaperDisplay() {
	imlib_context_set_display(display);
	imlib_context_set_visual(DefaultVisual(display, getDefaultScreen()));
	imlib_context_set_colormap(DefaultColormap(display, getDefaultScreen()));
	imlib_context_set_color_modifier(NULL);
	imlib_context_set_progress_function(NULL);
	imlib_context_set_operation(IMLIB_OP_COPY);
}
