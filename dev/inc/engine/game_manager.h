#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "game_object.h"

// Global variables.
extern struct_game_object global_game_object;

void engine_game_manager_init();
void engine_game_manager_draw_cheat();
void engine_game_manager_set_riff_select( unsigned char index );
void engine_game_manager_set_diff_select( unsigned char index );
void engine_game_manager_set_local_cheat( unsigned char cheat );
void engine_game_manager_set_game_finish( unsigned char ended );

#endif//__GAME_MANAGER_H__