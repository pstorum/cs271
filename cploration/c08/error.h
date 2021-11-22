#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <stdio.h>
#include <stdarg.h>

enum exitcode{
	/*
 * Error code 1 represents that given file does not exist.
 */
	EXIT_INCORRECT_ARGUMENTS = 1,
	EXIT_CANNOT_OPEN_FILE,
	EXIT_TOO_MANY_INSTRUCTIONS,
	EXIT_INVALID_LABEL,
	EXIT_SYMBOL_ALREADY_EXISTS
};
void exit_program(enum exitcode code, ...);
#endif