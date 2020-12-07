#ifndef __CURSOR_OBJECT_H__
#define __CURSOR_OBJECT_H__

#include "global_manager.h"

typedef struct tag_struct_cursor_object
{
	unsigned char maximum;
	unsigned char selects;
	unsigned char text_xPos;
	unsigned char text_yPos[ MAX_OPTION ];
	unsigned char sprite_xPos;
	unsigned char sprite_yPos[ MAX_OPTION ];
	unsigned char prev_sprite;
	unsigned char curr_sprite;

} struct_cursor_object;

#endif//__CURSOR_OBJECT_H__