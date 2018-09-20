#ifndef __P2DEFS_H__
#define __P2DEFS_H__

#include <stdio.h>

//  NULL just in case ----------------------

#ifdef NULL
#undef NULL
#endif
#define NULL  0

// Deletes a buffer
#define RELEASE( x ) \
    {                        \
    if( x != NULL )        \
	    {                      \
      delete x;            \
	  x = NULL;              \
	    }                      \
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
    {                              \
    if( x != NULL )              \
	    {                            \
      delete[] x;                \
	  x = NULL;                    \
	    }                            \
                              \
    }

#define IN_RANGE( value, min, max ) ( ((value) >= (min) && (value) <= (max)) ? 1 : 0 )
#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define TO_BOOL( a )  ( (a != 0) ? true : false )

typedef unsigned int uint;
typedef unsigned char uchar;

template <class VALUE_TYPE> void SWAP(VALUE_TYPE& a, VALUE_TYPE& b)
{
	VALUE_TYPE tmp = a;
	a = b;
	b = tmp;
}

// Standard string size
#define SHORT_STR	32
#define MID_STR		255
#define HUGE_STR	8192

// TODO 5: Improve config.xml to store all configuration variables that we have as macros
// Use a section with the name of each module (see Module::name)


/*#define FULLSCREEN App->doc.child("config").child("window").child_value("fullscreen")
#define BORDERLESS App->doc.child("config").child("window").child_value("borderless")
#define RESIZABLE App->doc.child("config").child("window").child_value("resizable")
#define FULLSCREEN_WINDOW App->doc.child("config").child("window").child_value("fullscreen_window")
#define TITLE App->doc.child("config").child("window").child_value("name")
#define WIDTH App->doc.child("config").child("window").child_value("width")
#define HEIGHT App->doc.child("config").child("window").child_value("height")
#define SCALE App->doc.child("config").child("window").child_value("scale")*/

// Joins a path and file
inline const char* const PATH(const char* folder, const char* file)
{
	static char path[MID_STR];
	sprintf_s(path, MID_STR, "%s/%s", folder, file);
	return path;
}

#endif