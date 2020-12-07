#ifndef __QUIZ_OBJECT_H__
#define __QUIZ_OBJECT_H__

#include "global_manager.h"

// Quiz Manager.
typedef struct tag_struct_quiz_object
{
	unsigned char quiz_riff_numbs;
	unsigned char quiz_riffs_play;
	unsigned char quiz_difficulty;
	unsigned char quiz_riff_index;

	unsigned char quiz_selections;
	unsigned short	quiz_saved[ MAX_OPTION * MAX_DIFFICULTY ];
	unsigned short	quiz_ended;
	unsigned short	quiz_total;

} struct_quiz_object;

extern const char *quiz_years[ MAX_OPTION ];
extern const char *quiz_line1[ MAX_OPTION ];
extern const char *quiz_line2[ MAX_OPTION ];
extern const char *quiz_line3[ MAX_OPTION ];
extern const char *quiz_line4[ MAX_OPTION ];
extern const unsigned char quiz_yPos[ MAX_OPTION ];
extern const unsigned char quiz_number[ MAX_OPTION ];
extern unsigned char quiz_saving[ MAX_RIFFS ];
extern unsigned char quiz_answer[ MAX_RIFFS ];
extern unsigned char quiz_select[ MAX_RIFFS ];
extern unsigned char quiz_option[ MAX_RIFFS ][ MAX_OPTION ];

#endif//__QUIZ_OBJECT_H__