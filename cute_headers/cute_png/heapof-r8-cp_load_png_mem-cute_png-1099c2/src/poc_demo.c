#define CUTE_PNG_IMPLEMENTATION
#include "cute_png.h"                   // cute_png.h v1.05
#include <string.h>

int main( )
{
    const char* src = "../poc/sample9.png";
    cp_image_t png_img = cp_load_png(src);
    memset(&png_img, 0, sizeof(cp_image_t));
    return 0;
}
