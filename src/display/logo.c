#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_LOGO
#define LV_ATTRIBUTE_IMG_LOGO
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LOGO uint8_t logo_map[] = {
  0x00, 0x00, 0x00, 0x00, 	/*Color of index 0*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 1*/

  0x0e, 0x01, 0x80, 
  0x1f, 0x06, 0xc0, 
  0x7f, 0xc8, 0xf0, 
  0xff, 0xf0, 0xf8, 
  0xbf, 0xfc, 0xfc, 
  0x9f, 0xfe, 0xfc, 
  0x87, 0xff, 0xfc, 
  0x81, 0xff, 0xfc, 
  0x80, 0x7f, 0xfc, 
  0x80, 0x3f, 0xfc, 
  0x80, 0x0f, 0xfc, 
  0x80, 0x03, 0xfc, 
  0x82, 0x00, 0xfc, 
  0x83, 0x80, 0x7c, 
  0x83, 0xc0, 0x1c, 
  0x83, 0xf0, 0x04, 
  0x63, 0xcc, 0x18, 
  0x1b, 0x03, 0x30, 
  0x06, 0x00, 0xc0, 
};

const lv_img_dsc_t logo = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 22,
  .header.h = 19,
  .data_size = 65,
  .data = logo_map,
};