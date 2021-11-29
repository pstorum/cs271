#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "hack.h"

#define MAX_LINE_NUMBER 200
#define MAX_LABEL_LENGTH (MAX_LINE_NUMBER - 2)
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS

typedef int16_t hack_addr;
typedef int16_t opcode;


enum instr_type{
	Invalid_inst = -1,
	A_Type_inst,
	C_Type_inst
};

typedef struct c_instruction{
	opcode a:1;
	opcode comp:6;
	opcode dest:3;
	opcode jump:3;
}c_instruction;

typedef struct a_instruction{
	union{
		hack_addr x;
		char * y;
	};
	bool is_addr;
}a_instruction;

typedef struct instruction{
	union{
		c_instruction;
		a_instruction;
	};
	enum instr_type type;
}instruction;

char *strip(char *s);
void parse(FILE * file);
char is_Atype(const char *);
char is_label(const char *);
char is_Ctype(const char *);
char *extract_label(const char *line, char* label);
void add_predefined_symbols();
bool parse_A_instruction(const char *line, a_instruction *instr);

#endif