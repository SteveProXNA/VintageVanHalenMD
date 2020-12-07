#include "score_screen.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"

void screen_score_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;

	engine_cursor_manager_hide();
	engine_graphics_manager_clear_half();

	engine_font_manager_text( LOCALE_SUMMARY_SCORE, 1, 7 );
	engine_text_manager_draw_lines( 10, 6 );
	engine_text_manager_draw_lines_extra( 4, 2, 1 );
	engine_score_manager_draw_summary( qo->quiz_riffs_play );
}

void screen_score_screen_update( unsigned char *screen_type )
{
	unsigned char input;

	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		// Game is not completed!
		engine_game_manager_set_game_finish( completion_type_nop );
		*screen_type = screen_type_over;
		return;
	}

	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		*screen_type = screen_type_play;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_score;
}
