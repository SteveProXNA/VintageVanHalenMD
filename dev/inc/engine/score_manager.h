#ifndef __SCORE_MANAGER__
#define __SCORE_MANAGER__

#include "score_object.h"

// Global variables.
extern struct_score_object global_socre_object;

void engine_score_manager_init();
void engine_score_manager_reset();
void engine_score_manager_update( unsigned char index, unsigned char answer );
void engine_score_manager_draw();
void engine_score_manager_draw_percent( unsigned char index );
void engine_score_manager_draw_summary( unsigned char played );

void engine_score_manager_set_score_percent( unsigned char index, unsigned char input );
void engine_score_manager_set_score_correct( unsigned char index, unsigned short saved );
void engine_score_manager_set_score_answerd( unsigned char index, unsigned short saved );

#endif//__SCORE_MANAGER__