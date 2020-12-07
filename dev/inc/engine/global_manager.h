#ifndef __GLOBAL_MANAGER__
#define __GLOBAL_MANAGER__

#define MAX_SCREEENS			17

#define MAX_ALBUMS				12
#define MAX_SONGS				13
#define TOT_SONGS				126
#define MAX_RIFFS				40
#define MAX_SAMPLES				10
#define MAX_EFFECTS				4
#define MAX_INTROS				2
#define MAX_MUSICS				1
#define MAX_MENUS				2
#define MAX_OPTION				4
#define MAX_DIFFICULTY			2
#define MAX_SPRITES				4
#define MAX_TEXTER				39
#define MAX_EDDIES				23
#define EDDIE_IMAGES			9

#define PALETTE1_TILES			1
#define PALETTE2_TILES			240

#define SFX_RIFF_START			65
#define SFX_EFFECT_START		SFX_RIFF_START + MAX_RIFFS
#define SFX_INTRO_START			SFX_EFFECT_START + MAX_EFFECTS
#define SFX_MUSIC_START			SFX_INTRO_START + MAX_INTROS

#define BANNER_Y				4
#define OPTION_X				4

#define MAX_BYTE_VALUE			255
#define MAX_INT_VALUE			65535
#define INVALID_INDEX			-1

#endif//__GLOBAL_MANAGER__