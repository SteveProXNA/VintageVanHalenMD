#include "music_object.h"

const char *music_years[ MAX_ALBUMS ] = 
{
	"1978", 
	"1979", 
	"1980", 
	"1981", 
	"1982", 
	"1984", 
	"1986", 
	"1988", 
	"1991", 
	"1995", 
	"1998", 
	"2012"
};

const char *music_album1[ MAX_ALBUMS ] =
{
	"VAN HALEN",
	"VAN HALEN II",
	"WOMEN and",
	"FAIR WARNING",
	"DIVER DOWN",
	"1984",
	"5150",
	"OU812",
	"FOR UNLAWFUL",
	"BALANCE",
	"VAN HALEN III",
	"A DIFFERENT",
};

const char *music_album2[ MAX_ALBUMS ] =
{
	"", "", "CHILDREN FIRST", "", "", "",
	"", "", "CARNAL KNOWLEDGE", "", "", "KIND of TRUTH"
};

const char *music_songs1[ TOT_SONGS ] =
{
	"Runnin' with the",
	"Eruption",
	"You Really Got",
	"Ain't Talkin'",
	"I'm the One",
	"Jamie's Cryin'",
	"Atomic Punk",
	"Feel Your Love",
	"Little Dreamer",
	"Ice Cream Man",
	"On Fire",
	"You're No Good",
	"Dance the Night",
	"Somebody Get Me",
	"Bottoms Up!",
	"Outta Love Again",
	"Light Up the Sky",
	"Spanish Fly",
	"D.O.A.",
	"Women in Love...",
	"Beautiful Girls",
	"And the Cradle",
	"Everybody Wants",
	"Fools",
	"Romeo Delight",
	"Tora! Tora!",
	"Loss of Control",
	"Take Your",
	"Could This Be",
	"In a Simple",
	"Mean Street",
	"Dirty Movies",
	"Sinner's Swing!",
	"Hear About It",
	"Unchained",
	"Push Comes to",
	"So This Is Love?",
	"Sunday Afternoon",
	"One Foot Out the",
	"Where Have All",
	"Hang 'Em High",
	"Cathedral",
	"Secrets",
	"Intruder",
	"(Oh) Pretty",
	"Dancing in the ",
	"Little Guitars",
	"Little Guitars",
	"Big Bad Bill",
	"The Full Bug",
	"Happy Trails",
	"1984",
	"Jump",
	"Panama",
	"Top Jimmy",
	"Drop Dead Legs",
	"Hot for Teacher",
	"I'll Wait",
	"Girl Gone Bad",
	"House of Pain",
	"Good Enough",
	"Why Can't This",
	"Get Up",
	"Dreams",
	"Summer Nights",
	"Best of Both",
	"Love Walks In",
	"5150",
	"Inside",
	"Mine All Mine",
	"When It's Love",
	"A.F.U.",
	"Cabo Wabo",
	"Source of",
	"Feels So Good",
	"Finish What Ya",
	"Black and Blue",
	"Sucker in a 3",
	"Poundcake",
	"Judgement Day",
	"Spanked",
	"Runaround",
	"Pleasure Dome",
	"In 'n' Out",
	"Man on a Mission",
	"The Dream Is",
	"Right Now",
	"316",
	"Top of the World",
	"The Seventh Seal",
	"Can't Stop",
	"Don't Tell Me",
	"Amsterdam",
	"Big Fat Money",
	"Strung Out",
	"Not Enough",
	"Aftershock",
	"Doin' Time",
	"Baluchitherium",
	"Take Me Back",
	"Feelin'",
	"Neworld",
	"Without You",
	"One I Want",
	"From Afar",
	"Dirty Water Dog",
	"Once",
	"Fire in the Hole",
	"Josephina",
	"Year to the Day",
	"Primary",
	"Ballot or the",
	"How Many Say I",
	"Tattoo",
	"She's the Woman",
	"You and Your",
	"China Town",
	"Blood and Fire",
	"Bullethead",
	"As Is",
	"Honey baby",
	"The Trouble with",
	"Outta Space",
	"Stay Frosty",
	"Big River",
	"Beats Workin'",
};

const char *music_songs2[ TOT_SONGS ] =
{
	"Devil",
	"",
	"Me",
	"bout Love",
	"",
	"",
	"",
	"Tonight",
	"",
	"",
	"",
	"",
	"Away",
	"a Doctor",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Will Rock...",
	"Some!!",
	"",
	"",
	"",
	"",
	"Whiskey Home",
	"Magic?",
	"Rhyme",
	"",
	"",
	"",
	"Later",
	"",
	"Shove",
	"",
	"in the Park",
	"Door",
	"Good Times Gone!",
	"",
	"",
	"",
	"",
	"Woman",
	"Street",
	"(Intro)",
	"",
	"(Sweet William)",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Be Love",
	"",
	"",
	"",
	"Worlds",
	"",
	"",
	"",
	"",
	"",
	"Naturally Wired",
	"",
	"Infection",
	"",
	"Started",
	"",
	"Piece",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Over",
	"",
	"",
	"",
	"",
	"Lovin' You",
	"What Love Can Do",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"(Deja Vu)",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"Bullet",
	"",
	"",
	"",
	"Blues",
	"",
	"",
	"",
	"",
	"sweetie doll",
	"Never",
	"",
	"",
	"",
	"",
};

const unsigned char music_riffs[ MAX_RIFFS ] =
{
	0x00, 0x03, 0x04, 0x07, 0x09, 0x12, 0x15, 0x18, 0x21, 0x23,
	0x30, 0x32, 0x33, 0x34, 0x41, 0x52, 0x54, 0x55, 0x57, 0x58,
	0x60, 0x64, 0x65, 0x67, 0x72, 0x73, 0x76, 0x77, 0x80, 0x81,
	0x83, 0x87, 0x89, 0x8A, 0x91, 0x92, 0x97, 0x9B, 0xA7, 0xB2,
};

const unsigned char music_intro[ MAX_SAMPLES ] =
{
	0, 1, 10, 13, 15, 28, 33, 35, 36, 39
};

const unsigned char music_count[ MAX_ALBUMS ] =
{
	11, 10, 9, 9, 12, 9, 9, 9, 11, 12, 12, 13
};

const unsigned char music_total[ MAX_ALBUMS ] =
{
	0, 11, 21, 30, 39, 51, 60, 69, 78, 89, 101, 113
};