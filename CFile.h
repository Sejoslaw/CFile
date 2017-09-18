/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw
*/

#ifndef CFILE_H_INCLUDED
#define CFILE_H_INCLUDED

/// ============================================ Additional Includes

/// Standard I/O C Library
#include <stdio.h>

/// ============================================ Definitions

/// Windows has NULL declared
#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void*)0)
    #endif
#endif // NULL

/// File Modes
#define FILE_MODE_READ "r"
#define FILE_MODE_READ_BINARY "rb"
#define FILE_MODE_WRITE "w"
#define FILE_MODE_WRITE_BINARY "wb"
#define FILE_MODE_APPEND "a"
#define FILE_MODE_APPEND_BINARY "ab"
#define FILE_MODE_READ_WRITE "r+"
#define FILE_MODE_READ_WRITE_BINARY "r+b"
#define FILE_MODE_READ_WRITE_CREATE "w+"
#define FILE_MODE_READ_WRITE_CREATE_BINARY "w+b"
#define FILE_MODE_READ_WRITE_CREATE_APPEND "a+"
#define FILE_MODE_READ_WRITE_CREATE_APPEND_BINARY "a+b"

/// ============================================ Operations

/// Open selected File in given mode.
/// For different Modes see FILE_MODE definitions in this file in "Definitions" section.
FILE* open_file(const char *file_name, const char *mode)
{
    return fopen(file_name, mode);
}

/// Close the given File.
int close_file(FILE *file)
{
    return fclose(file);
}

/// Read single character from File.
int read_character_from_file(FILE *file)
{
    return fgetc(file);
}

/// Read n-1 characters from input stream from File.
char* read_input_stream(char *buffer, int number_of_characters, FILE *file)
{
    return fgets(buffer, number_of_characters, file);
}

/// Write selected character to given File.
int write_character_to_file(int character, FILE *file)
{
    return fputc(character, file);
}

/// Write to File using fprintf method.
int write_to_file_printf(FILE *file, const char *text)
{
    return fprintf(file, text);
}

/// Write given text to File.
int write_to_file_puts(const char *text, FILE *file)
{
    return fputs(text, file);
}

/// Read binary File.
size_t read_binary_file(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *file)
{
    return fread(ptr, size_of_elements, number_of_elements, file);
}

/// Wirte to binary File.
size_t write_binary_file(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *file)
{
    return fwrite(ptr, size_of_elements, number_of_elements, file);
}

/// Save current stream to File.
/// File will still be open.
int save_file(FILE *file)
{
    return fflush(file);
}

/// Set the cursor position in file which depends on "mode".
/// Mode == 0 => Move cursor from the File beginning,
/// Mode == 1 => Move cursor from the current position,
/// Mode == 2 => Move cursor from the File end.
/// Returns not zero if something went wrong.
int go_to_position_in_file(FILE *file, long offset, int mode)
{
    return fseek(file, offset, mode);
}

/// Moves cursor to the beginning of given File
void go_to_beginning(FILE *file)
{
    rewind(file);
}

/// Returns the position of cursor in given File.
long get_cursor_position(FILE *file)
{
    return ftell(file);
}

#endif // CFILE_H_INCLUDED

/***
	License page: http://www.zlib.net/zlib_license.html
	version 1.2.11, January 15th, 2017
	  Copyright (C) 2010-2017 Krzysztof Dobrzynski
	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.
	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:
	  1. The origin of this software must not be misrepresented; you must not
		 claim that you wrote the original software. If you use this software
		 in a product, an acknowledgment in the product documentation would be
		 appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		 misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.
	  Krzysztof Dobrzynski
	  k.dobrzynski94@gmail.com
*/
