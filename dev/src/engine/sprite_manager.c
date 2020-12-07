#include "sprite_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "gfx_sprites.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private fields.
Sprite* sprites[ MAX_SPRITES ] = { NULL, NULL, NULL, NULL };
const SpriteDefinition* spriteDefList[ MAX_SPRITES ] = { &gfx_actor, &gfx_chose, &gfx_right, &gfx_wrong };

// Private function.
static void init_sprite( const unsigned char index );
static void palette_sprite();

void engine_sprite_manager_init()
{
	SPR_init( 0, 0, 0 );

	init_sprite( sprite_type_actor );
	init_sprite( sprite_type_chose );
	init_sprite( sprite_type_right );
	init_sprite( sprite_type_wrong );

	palette_sprite();
}

void engine_sprite_manager_hide( unsigned char sprite )
{
	SPR_setVisibility( sprites[ sprite ], HIDDEN );
}

void engine_sprite_manager_update()
{
	SPR_update();
}

void engine_sprite_manager_palette()
{
	palette_sprite();
}

void engine_sprite_manager_draw( const unsigned char index, unsigned char x, unsigned char y )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;

	spriteDef = spriteDefList[ index ];
	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	VDP_setPalette( PAL3, data );
	SPR_setPosition( sprites[ index ], x, y );
	palette_sprite();
	SPR_setVisibility( sprites[ index ], VISIBLE );
}

static void init_sprite( const unsigned char index )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;

	spriteDef = spriteDefList[ index ];
	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	VDP_setPalette( PAL3, data );
	sprites[ index ] = SPR_addSprite( spriteDef, 0, 0, TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	SPR_setVisibility( sprites[ index ], HIDDEN );
}
static void palette_sprite()
{
	// Sega Genesis deep yellow hex color:
	unsigned short color = RGB24_TO_VDPCOLOR( 0xFFE57C );
	VDP_setPaletteColor( PAL3 * 16 + 15, color );
}