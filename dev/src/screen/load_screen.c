#include "load_screen.h"
#include "banner_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"

void screen_load_screen_load()
{
	engine_font_manager_text( LOCALE_BLANK_SIZE30, 5, BANNER_Y );

	// Reset variables.
	engine_banner_manager_stats();
	engine_score_manager_reset();
	engine_quiz_manager_reset();

	engine_score_manager_draw();
	engine_quiz_manager_draw();

	// Load quiz questions.
	engine_quiz_manager_load_random();

	// Assume the game will be completed.
	engine_game_manager_set_game_finish( completion_type_yes );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();
	*screen_type = screen_type_part;
}