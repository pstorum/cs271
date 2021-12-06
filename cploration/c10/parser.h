#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "hack.h"
#include "symtable.h"

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
	opcode comp:7;
	opcode dest:4;
	opcode jump:4;
}c_instruction;

typedef struct a_instruction{
	union{
		hack_addr x;
		char * y;
	};
	bool is_addr;
}a_instruction;

typedef struct instruction{
	union Instr{
		c_instruction c;
		a_instruction a;
	}instr;
	enum instr_type itype;
}instruction;

char *strip(char *s);
int parse(FILE * file, instruction *instructions);
char is_Atype(const char *);
char is_label(const char *);
char is_Ctype(const char *);
char *extract_label(const char *line, char* label);
void add_predefined_symbols();
bool parse_A_instruction(const char *line, a_instruction *instr);
void parse_C_instruction(char *line, c_instruction *instr);


#endif