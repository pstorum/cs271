#include "parser.h"

char *strip(char *s){
	char s_new[strlen(s)+1];	
	int i = 0;
	for(char *s2 = s; *s2; s2++){
		if (*s2 == '/' && *(s2+1) == '/'){
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
void parse(FILE * file){
	char line[MAX_LINE_NUMBER] = {0};
	char label[MAX_LABEL_LENGTH] = {0};
	while (fgets(line, sizeof(line), file)){
		strip(line);
		if (!*line){
			continue;
		}
		char inst_type;
		if (is_Atype(line) == 1){
			inst_type = 'A';
			printf("%c  %s\n", inst_type, line);
		}else if (is_label(line) == 1){
			extract_label(line, label);
			inst_type = 'L';
			printf("%c  %s\n", inst_type, label);
		}else if (is_Ctype(line) == 1){
			inst_type = 'C';
			printf("%c  %s\n", inst_type, line);
		}
	}
}

char is_Atype(const char *line){
	if(*line == '@'){
		return 1;
	}else{
		return 0;
	}

}
char is_label(const char *line){
	if(*line != '('){
		return 0;
	}
	int line_len = strlen(line)-1;
	for (int x = 0; x < line_len; x++){
		line++;
	}
	if(*line != ')'){
		return 0;
	}else{
		return 1;
	}
		
}
char is_Ctype(const char *line){
	if (is_label(line) == 1){
		return 0;
	}else if(is_Atype(line) == 1){
		return 0;
	}else{
		return 1;
	}
}
char *extract_label(const char *line, char* label){	
	int i = 0;
	for(char *s2 = line; *s2; s2++){
		if (*s2 == '(' || *s2 == ')'){
			continue;
		}
		else if (!(isspace(*s2))){
			label[i++] = *s2;
		}
	}
	label[i] = '\0';
	return label;
}

	