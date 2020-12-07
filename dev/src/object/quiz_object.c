#include "quiz_object.h"

const char *quiz_years[ MAX_OPTION ] = { "", "", "", "" };
const char *quiz_line1[ MAX_OPTION ] = { "", "", "", "" };
const char *quiz_line2[ MAX_OPTION ] = { "", "", "", "" };
const char *quiz_line3[ MAX_OPTION ] = { "", "", "", "" };
const char *quiz_line4[ MAX_OPTION ] = { "", "", "", "" };
const unsigned char quiz_yPos[ MAX_OPTION ] = { 6, 12, 18, 24 };
const unsigned char quiz_number[ MAX_OPTION ] = { 5, 10, 20, 40 };
unsigned char quiz_saving[ MAX_RIFFS ] = { 0 };
unsigned char quiz_answer[ MAX_RIFFS ] = { 0 };
unsigned char quiz_select[ MAX_RIFFS ] = { 0 };
unsigned char quiz_option[ MAX_RIFFS ][ MAX_OPTION ] = { 0 };