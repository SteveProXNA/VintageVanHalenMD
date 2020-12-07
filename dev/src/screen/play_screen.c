#include "play_screen.h"
#include "audio_manager.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"

void screen_play_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_quiz_object *qo = &global_quiz_object;
	engine_graphics_manager_clear_half();

	engine_score_manager_draw_percent( quiz_saving[qo->quiz_riff_index] );
	if( go->game_localcheat )
	{
		engine_quiz_manager_cheat();
	}

	engine_cursor_manager_load_large( MAX_OPTION, qo->quiz_selections, OPTION_X, quiz_yPos, quiz_years, quiz_line1, quiz_line2, quiz_line3, quiz_line4 );
	engine_cursor_manager_draw();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_cursor_object *co = &global_cursor_object;
	struct_quiz_object *qo = &global_quiz_object;

	unsigned char input;
	unsigned char correct;
	unsigned char riff_index;
	unsigned char save_index;
	unsigned char answer;

	engine_sprite_manager_update();

	// Button A : answer question.
	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		riff_index = qo->quiz_riff_index;
		save_index = quiz_saving[ riff_index ];
		correct = quiz_select[ riff_index ];
		answer = co->selects == correct ? sprite_type_right : sprite_type_wrong;

		engine_audio_manager_play_effect( answer );
		engine_score_manager_update( save_index, answer );
		engine_cursor_manager_action( answer );

		*screen_type = screen_type_quiz;
		return;
	}

	// Button B : navigate to score screen.
	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		engine_cursor_manager_hide();
		engine_sprite_manager_update();
		engine_quiz_manager_selection( co->selects );
		*screen_type = screen_type_score;
		return;
	}

	// Button C : replay riff on demand.
	input = engine_input_manager_hold_buttonC();
	if( input )
	{
		riff_index = qo->quiz_riff_index;
		save_index = quiz_saving[ riff_index ];
		engine_audio_manager_play_riff( save_index );
	}


	input = engine_input_manager_hold_up();
	if( input )
	{
		engine_cursor_manager_move_up();
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_cursor_manager_move_down();
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_play;
}