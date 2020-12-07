#ifndef __ENUM_MANAGER__
#define __ENUM_MANAGER__

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_init = 2,
	screen_type_begin = 3,
	screen_type_intro = 4,
	screen_type_title = 5,
	screen_type_start = 6,
	screen_type_riff = 7,
	screen_type_diff = 8,
	screen_type_ready = 9,
	screen_type_load = 10,
	screen_type_part = 11,
	screen_type_play = 12,
	screen_type_quiz = 13,
	screen_type_score = 14,
	screen_type_stats = 15,
	screen_type_over = 16,

} enum_screen_type;

typedef enum tag_enum_sprite_type
{
	sprite_type_actor = 0,
	sprite_type_chose = 1,
	sprite_type_right = 2,
	sprite_type_wrong = 3,

} enum_sprite_type;

typedef enum tag_enum_difficulty_type
{
	difficulty_type_easy = 0,
	difficulty_type_hard = 1,

} enum_difficulty_type;

typedef enum tag_enum_completion_type
{
	completion_type_nop = 0,
	completion_type_yes = 1,

} enum_completion_type;

typedef enum tag_enum_cursor_type
{
	cursor_type_small = 0,
	cursor_type_large = 1,

} enum_cursor_type;

typedef enum tag_enum_movement_type
{
	movement_type_up = 0,
	movement_type_down = 1,

} enum_movement_type;

typedef enum tag_enum_stage_type
{
	event_stage_start = 0,
	event_stage_pause = 1,
	event_stage_menus = 2,

} enum_stage_type;

typedef enum tag_enum_effects_type
{
	effects_type_cheat = 0,
	effects_type_ready = 1,
	effects_type_right = 2,
	effects_type_wrong = 3,

} enum_effects_type;

typedef enum tag_enum_intros_type
{
	intros_type_dream = 0,
	intros_type_jumps = 1,

} enum_intros_type;

/*
typedef enum tag_enum_album_type
{
album_1978 = 0,		// Van Halen
album_1979 = 1,		// Van Halen II
album_1980 = 2,		// Women and Children First
album_1981 = 3,		// Fair Warning
album_1982 = 4,		// Diver Down
album_1984 = 5,		// 1984
album_1986 = 6,		// 5150
album_1988 = 7,		// OU812
album_1991 = 8,		// For Unlawful Carnal Knowledge
album_1995 = 9,		// Balance
album_1998 = 10,	// Van Halen III
album_2012 = 11,	// A Different Kind of Truth

} enum_album_type;
*/

#endif//__ENUM_MANAGER__
