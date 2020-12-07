#include "graphics_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

#define GAME_AREA_X				0
#define GAME_AREA_Y				6
#define GAME_AREA_W				40
#define GAME_AREA_H				22


void engine_graphics_manager_clear_area()
{
	VDP_clearTileMapRect( BG_A, GAME_AREA_X, GAME_AREA_Y, GAME_AREA_W, GAME_AREA_H );
}

void engine_graphics_manager_clear_half()
{
	VDP_clearTileMapRect( BG_A, GAME_AREA_X, GAME_AREA_Y, GAME_AREA_W / 2, GAME_AREA_H );
}

void engine_graphics_manager_clear_full()
{
	VDP_clearTileMapRect( BG_A, GAME_AREA_X, GAME_AREA_X, GAME_AREA_W, GAME_AREA_Y + GAME_AREA_H );
}

void engine_graphics_manager_clear_bottom()
{
	VDP_clearTileMapRect( BG_A, GAME_AREA_X, 24, GAME_AREA_W, 4 );
}
