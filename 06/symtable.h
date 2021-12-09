#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;

struct Symbol{
	hack_addr addr;
	char key;
}symbol;

struct Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *str);
struct Symbol *symtable_find(char * key);
void symtable_insert(char* key, hack_addr addr);
void symtable_display_table();

#endif