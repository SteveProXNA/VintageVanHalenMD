#include "image_manager.h"
#include "global_manager.h"
#include "image_object.h"
#include "gfx_tiles.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private helper function.
static void draw_image( const Image image, unsigned char palette, unsigned short tiles, unsigned char x, unsigned char y );

void engine_image_manager_draw_splash()
{
	draw_image( gfx_splash, PAL1, PALETTE1_TILES, 4, 2 );
}

void engine_image_manager_draw_header()
{
	draw_image( gfx_header, PAL1, PALETTE1_TILES, 2, 7 );
}

void engine_image_manager_draw_banner()
{
	draw_image( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
}

void engine_image_manager_draw_eddie( unsigned char index, unsigned char x, unsigned char y )
{
	const Image image = *image_eddie[ index ];
	draw_image( image, PAL2, PALETTE2_TILES, x, y );
}

static void draw_image( const Image image, unsigned char palette, unsigned short tiles, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( palette, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( palette, 0, 0, 0, tiles ), x, y, 0, CPU );
}