#include "error.h"
#include "symtable.h"
#include "parser.h"
#include "hack.h"

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
int parse(FILE * file, instruction *instructions){
	char line[MAX_LINE_NUMBER] = {0};
	char label[MAX_LABEL_LENGTH] = {0};
	unsigned int line_num;
	unsigned int instr_num = 0;	
	char tmp_line[MAX_LINE_NUMBER];
	instruction instr;
	add_predefined_symbols();
	while (fgets(line, sizeof(line), file)){
		line_num++;
		if (instr_num > MAX_INSTRUCTIONS){
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}
		strip(line);
		if (!*line){
			continue;
		}
		char inst_type;
		if (is_Atype(line) == 1){
			if (!parse_A_instruction(line, &instr.instr.a)){
				exit_program(EXIT_INVALID_A_INSTR, line_num, line);
			}
			instr.itype = A_Type_inst;
			inst_type = 'A';
			printf("%c  %s\n", inst_type, line);
		}else if (is_label(line) == 1){
			extract_label(line, label);
			if (isalpha(label[0]) == 0){
				exit_program(EXIT_INVALID_LABEL, line_num, line);
			}
			else if (symtable_find(label) != NULL){
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}
			else{
				symtable_insert(label,instr_num);
				continue;
			}
			inst_type = 'L';
			printf("%c  %s\n", inst_type, label);
		}else if (is_Ctype(line) == 1){
			strcpy(tmp_line, line);
			parse_C_instruction(tmp_line, &instr.instr.c);
			if(instr.instr.c.comp == -1){
				exit_program(EXIT_INVALID_C_COMP, line_num, line);
			}else if(instr.instr.c.dest == -1){
				exit_program(EXIT_INVALID_C_DEST, line_num, line);
			}else if(instr.instr.c.jump == -1){
				exit_program(EXIT_INVALID_C_JUMP, line_num, line);
			}
			instr.itype = C_Type_inst;
			inst_type = 'C';
			printf("%c  %s\n", inst_type, line);
		}
		instructions[instr_num++] = instr;
	}
	return instr_num;
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
	for(const char *s2 = line; *s2; s2++){
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
void add_predefined_symbols(){
	for(int x = 0; x < NUM_PREDEFINED_SYMBOLS; x++){
		predefined_symbol temp = predefined_symbols[x];
		symtable_insert(temp.key, temp.address);
	}
}
bool parse_A_instruction(const char *line, a_instruction *instr){
	char s[strlen(line)];
	strcpy(s, line+1);
	char *s_end = NULL;
	long result = strtol(s, &s_end, 10);
	if (s == s_end){
		instr->y = (char*)malloc(strlen(line));
		strcpy(instr->y, s);
		instr->is_addr = false;
	}else if(*s_end != 0){
		return false;
	}else{
		instr->y = result;
		instr->is_addr = true;
	}
	return true;
}

void parse_C_instruction(char *line, c_instruction *instr){
	char *temp_val;
	char *jump_val;
	char *dest_val;
	char *comp_val;
	int *a = 0;
	temp_val = strtok(line, ";");
	jump_val = line;
	dest_val = strtok(temp_val, "=");
	comp_val = temp_val;
	if (comp_val == NULL){
		comp_val=dest_val;
		dest_val=NULL;
	}
	instr->jump = str_to_jumpid(jump_val);
	instr->dest = str_to_destid(dest_val);
	instr->comp = str_to_compid(comp_val, a);
	instr->a = a;
}	
void assemble(const char * file_name, instruction* instructions, int num_instructions) {

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	