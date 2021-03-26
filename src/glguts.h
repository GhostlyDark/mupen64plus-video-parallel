#pragma once

#include "api/m64p_vidext.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct video_pixel
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    struct frame_buffer
    {
        struct video_pixel *pixels;
        uint32_t width;
        uint32_t height;
        uint32_t pitch;
        bool valid;
    };

    bool screen_write(struct frame_buffer *fb);
    void screen_read(struct frame_buffer *fb, bool alpha);
    void screen_init();
    void screen_adjust(int32_t width_out, int32_t height_out, int32_t *width, int32_t *height, int32_t *x, int32_t *y);
    void screen_update(void);
    void screen_toggle_fullscreen(void);
    void screen_close(void);
    void screen_swap(bool blank);

    extern int32_t window_width;
    extern int32_t window_height;
    extern int32_t window_fullscreen;

#ifdef __cplusplus
}
#endif
