#pragma once

#ifdef TARGET_PS3
#include <tiny3d.h>
#endif

#include <stdint.h>

// Font management
int TTFLoadFont(int set, const char *path, const void *from_memory, int size_from_memory);
void TTFUnloadFont(void);

// Convert character to bitmap
void TTF_to_Bitmap(uint8_t chr, uint8_t *bitmap, short *w, short *h, short *y_correction);

// Render UTF8 string to bitmap
int Render_String_UTF8(uint16_t *bitmap, int w, int h, const uint8_t *string, int sw, int sh);

// Initialize TTF texture table
uint16_t *init_ttf_table(uint16_t *texture);

// Reset character use flags per frame
void reset_ttf_frame(void);

// Window modes
typedef enum {
    WIN_AUTO_LF = 1,
    WIN_SKIP_LF = 2,
    WIN_DOUBLE_LF = 4
} TTFWindowMode;

// Set rendering window and mode
void set_ttf_window(int x, int y, int width, int height, uint32_t mode);

// Global rendering variables
extern float Y_ttf;
extern float Z_ttf;

// Display UTF8 string
int display_ttf_string(int posx, int posy, const char *string, uint32_t color, uint32_t bkcolor, int sw, int sh);
