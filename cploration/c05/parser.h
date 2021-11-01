#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_NUMBER 200

char *strip(char *s);
void parse(FILE * file);
char is_Atype(const char *);
char is_label(const char *);
char is_Ctype(const char *);