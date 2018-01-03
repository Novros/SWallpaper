#include "XWallpaperImage.h"

XWallpaperImage::XWallpaperImage(const std::string &imgPath) {
    img = imlib_load_image(imgPath.c_str());

    if (img != nullptr) {
        imlib_context_set_image(img);
        width = imlib_image_get_width();
        height = imlib_image_get_height();
    }
}

XWallpaperImage::~XWallpaperImage() {
    //imlib_free_image(); // FIXME - need only free this image not last
}

void XWallpaperImage::render(const Drawable &drawable, const int & width, const int & height, const int & x, const int & y) {
    if (img != nullptr) {
        imlib_context_set_drawable(drawable);
        imlib_context_set_anti_alias(antialias);
        imlib_context_set_dither(dither);
        imlib_context_set_blend(blend);
        imlib_context_set_angle(0);
        imlib_render_image_on_drawable_at_size(
                x,
                y,
                width == UNDEFINED_SIZE ? this->width : width,
                height == UNDEFINED_SIZE ? this->height : height
                );
    }
}


