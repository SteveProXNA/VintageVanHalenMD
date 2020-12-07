#ifndef __TEXT_OBJECT_H__
#define __TEXT_OBJECT_H__

#include "global_manager.h"

typedef struct tag_struct_text_object
{
	unsigned char posX;
	unsigned char posY;
	const char *text;

} struct_text_object;

// Global variable.
extern const struct_text_object global_text_object[ MAX_TEXTER ];

// Riff Screen.
extern const unsigned char riff_yPos[ MAX_OPTION ];
extern const char *riff_line1[ MAX_OPTION ];
extern const char *riff_line2[ MAX_OPTION ];

// Difficulty Screen.
extern const unsigned char diff_yPos[ MAX_MENUS ];
extern const char *diff_line1[ MAX_MENUS ];
extern const char *diff_line2[ MAX_MENUS ];
extern const char *diff_line3[ MAX_MENUS ];
extern const char *diff_line4[ MAX_MENUS ];

#endif//__TEXT_OBJECT_H__