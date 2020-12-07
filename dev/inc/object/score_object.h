#ifndef __SCORE_OBJECT_H__
#define __SCORE_OBJECT_H__

#include "global_manager.h"

// Score Manager.
typedef struct tag_struct_score_object
{
	unsigned char score_correct;
	unsigned char score_answerd;
	unsigned short saved_correct[ MAX_RIFFS ];
	unsigned short saved_answerd[ MAX_RIFFS ];

} struct_score_object;

#endif//__SCORE_OBJECT_H__