#include "parser.h"

char *strip(char *s){
	char s_new[strlen(s)+1];	
	int i = 0;
	for(char *s2 = s; *s2; s2++){
		if (*s2 == '/' && *(s+1) == '/'){
			break;
		}
		else if (!(isspace(*s2))){
			s_new[i++] = *s2;
		}
	}
	s_new[i] = '\0';
	strcpy(s, s_new);
	return s;
}
//TODO: The while loop runs 5 times when add.asm is called. Thinks line 5 is the last line.
void parse(FILE * file){
	char line[MAX_LINE_NUMBER] = {0};
	while (fgets(line, sizeof(line), file)){
		strip(line);
		if (*line == NULL){
			continue;
		}
		printf("%s",line);
	}
}

