#include "over_screen.h"
#include "audio_manager.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "hack_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"
#include "storage_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define SCORE_MUSIC_DELAY		600
#define SCORE_FLASH_DELAY		20

static void flash_score();
static unsigned char flash_count;
static unsigned short frame_count;

void screen_over_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_quiz_object *qo = &global_quiz_object;

	engine_cursor_manager_hide();
	engine_graphics_manager_clear_half();

	engine_font_manager_text( LOCALE_SUMMARY_OVER, 1, 7 );
	engine_text_manager_draw_lines( 10, 4 );
	engine_text_manager_draw_lines( 16, 2 );

	engine_score_manager_draw_summary( qo->quiz_riffs_play );

	engine_delay_manager_load( SCORE_MUSIC_DELAY );
	engine_audio_manager_stop();

	engine_quiz_manager_set_quiz_saved_all( go->game_completion );
	engine_storage_manager_write();

	engine_audio_manager_play_music( 0 );
	flash_count = 0;
	frame_count = 0;
}

void screen_over_screen_update( unsigned char *screen_type )
{
	struct_score_object *so = &global_socre_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char delay;
	unsigned char input;

	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_audio_manager_stop();
		*screen_type = screen_type_title;
		return;
	}

	frame_count++;
	if( 0 != so->score_answerd && so->score_correct == so->score_answerd )
	{
		if( 0 == frame_count % SCORE_FLASH_DELAY )
		{
			if( !ho->hack_delayspeed )
			{
				flash_count = 1 - flash_count;
			}

			if( flash_count )
			{
				engine_font_manager_text( LOCALE_OVER_PERFECT, 16, 23 );
			}
			else
			{
				flash_score();
			}
		}
	}

	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		engine_audio_manager_stop();
		*screen_type = screen_type_title;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_over;
}

static void flash_score()
{
	struct_game_object *go = &global_game_object;
	struct_score_object *so = &global_socre_object;
	if( go->game_completion )
	{
		if( 0 != so->score_answerd && so->score_correct == so->score_answerd )
		{
			engine_text_manager_draw_lines_palette( LOCALE_OVER_PERFECT, 16, 23 );
		}
	}
}