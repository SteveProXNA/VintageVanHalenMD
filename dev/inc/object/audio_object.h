#ifndef __AUDIO_OBJECT_H__
#define __AUDIO_OBJECT_H__

#include "global_manager.h"

extern const unsigned char *audio_riff[ MAX_RIFFS ];
extern const unsigned char *audio_effect[ MAX_EFFECTS ];
extern const unsigned char *audio_intro[ MAX_INTROS ];
extern const unsigned char *audio_music[ MAX_MUSICS ];

extern const unsigned int audio_riff_size[ MAX_RIFFS ];
extern const unsigned int audio_effect_size[ MAX_EFFECTS ];
extern const unsigned int audio_intro_size[ MAX_INTROS ];
extern const unsigned int audio_music_size[ MAX_MUSICS ];

#endif//__AUDIO_OBJECT_H__