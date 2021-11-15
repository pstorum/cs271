#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;

struct Symbol{
	char key; 
	hack_addr addr;
}symbol;

struct Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *str);
struct Symbol *find(char * key);
void insert(char* key, hack_addr addr);
void display_table();