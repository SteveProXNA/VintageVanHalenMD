#include "audio_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "audio_object.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Private helper function.
static void play_audio( const u8 id, const u8 priority, const u16 channel );
static void stop_audio();

void engine_audio_manager_init()
{
	unsigned char idx;
	const unsigned char *audio;
	unsigned int sized;

	// Initialize riffs.
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		audio = audio_riff[ idx ];
		sized = audio_riff_size[ idx ];
		SND_setPCM_XGM( SFX_RIFF_START + idx, audio, sized );
	}

	// Initialize effects.
	for( idx = 0; idx < MAX_EFFECTS; idx++ )
	{
		audio = audio_effect[ idx ];
		sized = audio_effect_size[ idx ];
		SND_setPCM_XGM( SFX_EFFECT_START + idx, audio, sized );
	}

	// Initialize intros.
	for( idx = 0; idx < MAX_INTROS; idx++ )
	{
		audio = audio_intro[ idx ];
		sized = audio_intro_size[ idx ];
		SND_setPCM_XGM( SFX_INTRO_START + idx, audio, sized );
	}

	// Initialize music.
	for( idx = 0; idx < MAX_MUSICS; idx++ )
	{
		audio = audio_music[ idx ];
		sized = audio_music_size[ idx ];
		SND_setPCM_XGM( SFX_MUSIC_START + idx, audio, sized );
	}
}

void engine_audio_manager_play_riff( unsigned char index )
{
	play_audio( SFX_RIFF_START + index, 1, SOUND_PCM_CH1 );
}

void engine_audio_manager_play_effect( unsigned char index )
{
	struct_hack_object *ho = &global_hack_object;
	if( ho->hack_delayspeed )
	{
		return;
	}

	play_audio( SFX_EFFECT_START + index, 1, SOUND_PCM_CH2 );
}

void engine_audio_manager_play_intro( unsigned char index )
{
	play_audio( SFX_INTRO_START + index, 1, SOUND_PCM_CH2 );
}

void engine_audio_manager_play_music( unsigned char index )
{
	play_audio( SFX_MUSIC_START + index, 1, SOUND_PCM_CH2 );
}

void engine_audio_manager_stop()
{
	stop_audio();
}

unsigned char engine_audio_manager_is_playing()
{
	return XGM_isPlayingPCM( SOUND_PCM_CH1_MSK ) || XGM_isPlayingPCM( SOUND_PCM_CH2_MSK );
}

static void play_audio( const u8 id, const u8 priority, const u16 channel )
{
	stop_audio();
	XGM_startPlayPCM( id, priority, channel );
}

static void stop_audio()
{
	if( XGM_isPlayingPCM( SOUND_PCM_CH1_MSK ) )
	{
		XGM_stopPlayPCM( SOUND_PCM_CH1 );
	}
	if( XGM_isPlayingPCM( SOUND_PCM_CH2_MSK ) )
	{
		XGM_stopPlayPCM( SOUND_PCM_CH2 );
	}
}