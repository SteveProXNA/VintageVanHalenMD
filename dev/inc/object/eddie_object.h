#ifndef __EDDIE_OBJECT_H__
#define __EDDIE_OBJECT_H__

#include "global_manager.h"

typedef struct tag_struct_eddie_object
{
	unsigned char eddie_index;
	char eddie_images[ EDDIE_IMAGES ];

} struct_eddie_object;

#endif//__EDDIE_OBJECT_H__