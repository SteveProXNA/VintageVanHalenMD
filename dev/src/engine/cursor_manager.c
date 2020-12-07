#include "cursor_manager.h"
#include "enum_manager.h"
#include "locale_manager.h"
#include "scribe_manager.h"
#include "sprite_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#include <string.h>
#else
#include <genesis.h>
#endif

// Global variables.
struct_cursor_object global_cursor_object;

static void load_cursor( unsigned char cursor, unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 );
static void move_cursor( unsigned char movement );

void engine_cursor_manager_load_small( unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **line1, const char **line2 )
{
	const char *options[ 1 ] = { LOCALE_BULLET_POINTS };
	const char *line3[ 1 ] = { "" };
	const char *line4[ 1 ] = { "" };
	load_cursor( sprite_type_actor, maximum, selects, xPos, yPos, options, line1, line2, line3, line4 );
}

void engine_cursor_manager_load_large( unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 )
{
	load_cursor( sprite_type_chose, maximum, selects, xPos, yPos, options, line1, line2, line3, line4 );
}

void engine_cursor_manager_move_up()
{
	move_cursor( movement_type_up );
}

void engine_cursor_manager_move_down()
{
	move_cursor( movement_type_down );
}

void engine_cursor_manager_action( unsigned char sprite )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char idx = co->selects;

	engine_scribe_manager_draw_options( co->curr_sprite, LOCALE_BLANK_SIZE4, co->text_xPos - 2, co->text_yPos[ idx ] );
	engine_sprite_manager_hide( co->curr_sprite );

	co->prev_sprite = co->curr_sprite;
	co->curr_sprite = sprite;
	engine_sprite_manager_draw( co->curr_sprite, co->sprite_xPos, co->sprite_yPos[ co->selects ] );
}

void engine_cursor_manager_draw()
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char idx;

	engine_scribe_manager_draw_line_palette( co->curr_sprite, PAL3, co->selects, co->text_xPos, co->text_yPos[ co->selects ] );
	VDP_setTextPalette( PAL0 );
	for( idx = 0; idx < co->maximum; idx++ )
	{
		engine_scribe_manager_draw_option( co->curr_sprite, idx, co->text_xPos - 2, co->text_yPos[ idx ] );
		if( co->selects == idx )
		{
			continue;
		}

		engine_scribe_manager_draw_line( co->curr_sprite, idx, co->text_xPos, co->text_yPos[ idx ] );
	}

	engine_sprite_manager_draw( co->curr_sprite, co->sprite_xPos, co->sprite_yPos[ co->selects ] );
}

void engine_cursor_manager_hide()
{
	struct_cursor_object *co = &global_cursor_object;
	engine_sprite_manager_hide( co->curr_sprite );
}

static void load_cursor( unsigned char cursor, unsigned char maximum, unsigned char selects, unsigned char xPos, const unsigned char *yPos, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char idx;

	co->prev_sprite = co->curr_sprite;
	co->curr_sprite = cursor;
	co->maximum = maximum;
	co->selects = selects;
	co->text_xPos = xPos;
	co->sprite_xPos = xPos - 4;
	for( idx = 0; idx < maximum; idx++ )
	{
		co->text_yPos[ idx ] = yPos[ idx ];
		co->sprite_yPos[ idx ] = yPos[ idx ] * 8;		// 8px per tile!
	}

	engine_scribe_manager_load_lines( cursor, maximum, options, line1, line2, line3, line4 );
	engine_sprite_manager_hide( co->prev_sprite );
}
static void move_cursor( unsigned char movement )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char yPos;

	yPos = co->text_yPos[ co->selects ];
	engine_scribe_manager_draw_line_palette( co->curr_sprite, PAL0, co->selects, co->text_xPos, yPos );

	if( movement_type_up == movement )
	{
		if( 0 == co->selects )
		{
			co->selects = co->maximum - 1;
		}
		else
		{
			co->selects--;
		}
	}
	else if( movement_type_down == movement )
	{
		if( co->maximum - 1 == co->selects )
		{
			co->selects = 0;
		}
		else
		{
			co->selects++;
		}
	}

	yPos = co->text_yPos[ co->selects ];
	engine_scribe_manager_draw_line_palette( co->curr_sprite, PAL3, co->selects, co->text_xPos, yPos );
	VDP_setTextPalette( PAL0 );

	engine_sprite_manager_draw( co->curr_sprite, co->sprite_xPos, co->sprite_yPos[ co->selects ] );
}