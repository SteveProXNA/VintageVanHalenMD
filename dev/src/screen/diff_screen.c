#include "diff_screen.h"
#include "audio_manager.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define DIFF_SCREEN_DELAY		100
#define DIFF_SCREEN_PAUSE		20

static unsigned char stage;
static void print_extra( unsigned char index );

void screen_diff_screen_load()
{
	struct_game_object *go = &global_game_object;
	engine_graphics_manager_clear_half();

	engine_text_manager_draw_lines( 2, 2 );
	engine_cursor_manager_load_small( MAX_MENUS, go->diff_selections, OPTION_X, diff_yPos, diff_line1, diff_line2 );
	engine_cursor_manager_draw();

	engine_game_manager_draw_cheat();
	print_extra( go->diff_selections );
	stage = event_stage_start;
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char delay;
	unsigned char input;

	engine_sprite_manager_update();
	if( event_stage_menus == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_ready;
		}

		return;
	}

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			engine_cursor_manager_hide();
			engine_sprite_manager_update();
			engine_delay_manager_load( DIFF_SCREEN_PAUSE );
			stage = event_stage_menus;
		}

		return;
	}

	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		engine_cursor_manager_hide();
		*screen_type = screen_type_riff;
		return;
	}

	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		engine_audio_manager_play_effect( effects_type_right );

		engine_game_manager_set_diff_select( co->selects );
		engine_quiz_manager_set_difficulty( co->selects );
		engine_cursor_manager_action( sprite_type_right );

		engine_delay_manager_load( DIFF_SCREEN_DELAY );
		stage = event_stage_pause;
		return;
	}

	input = engine_input_manager_hold_up();
	if( input )
	{
		engine_cursor_manager_move_up();
		print_extra( co->selects );
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_cursor_manager_move_down();
		print_extra( co->selects );
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_diff;
}

static void print_extra( unsigned char index )
{
	engine_font_manager_text( diff_line3[ index ], 1, 22 );
	engine_font_manager_text( diff_line4[ index ], 1, 23 );
}