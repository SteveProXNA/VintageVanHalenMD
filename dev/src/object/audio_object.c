#include "audio_object.h"
#include "sfx_effects.h"
#include "sfx_intros.h"
#include "sfx_musics.h"
#include "sfx_riffs.h"

const unsigned char *audio_riff[ MAX_RIFFS ] =
{
	sfx_riff_00,
	sfx_riff_03,
	sfx_riff_04,
	sfx_riff_07,
	sfx_riff_09,
	sfx_riff_12,
	sfx_riff_15,
	sfx_riff_18,
	sfx_riff_21,
	sfx_riff_23,
	sfx_riff_30,
	sfx_riff_32,
	sfx_riff_33,
	sfx_riff_34,
	sfx_riff_41,
	sfx_riff_52,
	sfx_riff_54,
	sfx_riff_55,
	sfx_riff_57,
	sfx_riff_58,
	sfx_riff_60,
	sfx_riff_64,
	sfx_riff_65,
	sfx_riff_67,
	sfx_riff_72,
	sfx_riff_73,
	sfx_riff_76,
	sfx_riff_77,
	sfx_riff_80,
	sfx_riff_81,
	sfx_riff_83,
	sfx_riff_87,
	sfx_riff_89,
	sfx_riff_8A,
	sfx_riff_91,
	sfx_riff_92,
	sfx_riff_97,
	sfx_riff_9B,
	sfx_riff_A7,
	sfx_riff_B2,
};

const unsigned int audio_riff_size[ MAX_RIFFS ] =
{
	81408,
	50944,
	60160,
	64256,
	98048,
	59648,
	67072,
	86016,
	92928,
	62976,
	68864,
	56064,
	56832,
	99840,
	54272,
	97024,
	59136,
	66816,
	98048,
	75008,
	123136,
	82176,
	61184,
	90880,
	67328,
	82688,
	101120,
	71936,
	90880,
	77568,
	87808,
	102656,
	43776,
	107264,
	100608,
	65280,
	101120,
	91648,
	101632,
	57600,
};

const unsigned char *audio_effect[ MAX_EFFECTS ] =
{
	sfx_cheat,
	sfx_ready,
	sfx_right,
	sfx_wrong,
};
const unsigned int audio_effect_size[ MAX_EFFECTS ] =
{
	13568,
	15872,
	16384,
	14592,
};

const unsigned char *audio_intro[ MAX_INTROS ] =
{
	sfx_dream,
	sfx_jumps,
};
const unsigned int audio_intro_size[ MAX_INTROS ] =
{
	196864,
	132608,
};

const unsigned char *audio_music[ MAX_MUSICS ] =
{
	sfx_music,
};
const unsigned int audio_music_size[ MAX_MUSICS ] =
{
	140544,
};