#ifndef __HACK_H__
#define __HACK_H__

#define NUM_PREDEFINED_SYMBOLS 23
#define LONGEST_PREDEFINED_SYMBOL 7

typedef enum symbol_id {
	SYM_R0 = 0,
	SYM_R1 = 1,
	SYM_R2 = 2,
	SYM_R3 = 3,
	SYM_R4 = 4,
	SYM_R5 = 5,
	SYM_R6 = 6,
	SYM_R7 = 7,
	SYM_R8 = 8,
	SYM_R9 = 9,
	SYM_R10 = 10,
	SYM_R11 = 11,
	SYM_R12 = 12,
	SYM_R13 = 13,
	SYM_R14 = 14,
	SYM_R15 = 15,
	SYM_SCREEN = 16384,
	SYM_KBD = 24576,
	SYM_SP = 0,
	SYM_LCL = 1,
	SYM_ARG = 2,
	SYM_THIS = 3,
	SYM_THAT = 4,
} symbol_id;	

typedef struct predefined_symbol{
	char key[LONGEST_PREDEFINED_SYMBOL];
	int16_t address;
}predefined_symbol;

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
	{"R0", SYM_R0},
	{"R1", SYM_R1},
	{"R2", SYM_R2},
	{"R3", SYM_R3},
	{"R4", SYM_R4},
	{"R5", SYM_R5},
	{"R6", SYM_R6},
	{"R7", SYM_R7},
	{"R8", SYM_R8},
	{"R9", SYM_R9},
	{"R10", SYM_R10},
	{"R11", SYM_R11},
	{"R12", SYM_R12},
	{"R13", SYM_R13},
	{"R14", SYM_R14},
	{"R15", SYM_R15},
	{"SCREEN", SYM_SCREEN},
	{"KBD", SYM_KBD},
	{"SP", SYM_SP},
	{"LCL", SYM_LCL},
	{"ARG", SYM_ARG},
	{"THIS", SYM_THIS},
	{"THAT", SYM_THAT}
};

typedef enum jump_id {
	JMP_INVALID = -1,
	JMP_NULL,
	JMP_JGT,
	JMP_JEQ,
	JMP_JGE,
	JMP_JLT,
	JMP_JNE,
	JMP_JLE,
	JMP_JMP
}jump_id;

typedef enum dest_id {
	DST_INVALID = -1,
	DST_NULL,
	DST_M,
	DST_D,
	DST_MD,
	DST_A,
	DST_AM,
	DST_AD,
	DST_AMD
}dest_id;

typedef enum comp_id{
	COMP_INVALID=-1,
	COMP_0=42,
	COMP_1=63,
	COMP_Neg1=58,
	COMP_D=12,
	COMP_A=48,
	COMP_NotD=13,
	COMP_NotA=49,
	COMP_NegD=15,
	COMP_NegA=51,
	COMP_DPos1=31,
	COMP_APos1=55,
	COMP_DNeg1=14,
	COMP_ANeg1=50,
	COMP_DPosA=2,
	COMP_DNegA=19,
	COMP_ANegD=7,
	COMP_DAndA=0,
	COMP_DOrA=21,
	COMP_M=48,
	COMP_NotM=49,
	COMP_NegM=51,
	COMP_MPos1=55,
	COMP_MNeg1=50,
	COMP_DPosM=2,
	COMP_DNegM=19,
	COMP_MNegD=7,
	COMP_DAndM=0,
	COMP_DOrM=21
}comp_id;

static inline jump_id str_to_jumpid(const char *s){
	jump_id id = JMP_INVALID;
	if (s == NULL) {
		id = JMP_NULL;
	}else if(strcmp(s, "JGT") == 0) {
		id = JMP_JGT;
	}else if(strcmp(s, "JEQ") == 0) {
		id = JMP_JEQ;
	}else if(strcmp(s, "JGE") == 0) {
		id = JMP_JGE;
	}else if(strcmp(s, "JLT") == 0) {
		id = JMP_JLT;
	}else if(strcmp(s, "JNE") == 0) {
		id = JMP_JNE;
	}else if(strcmp(s, "JLE") == 0) {
		id = JMP_JLE;
	}else if(strcmp(s, "JMP") == 0) {
		id = JMP_JMP;
	}
	return id;	
}

static inline dest_id str_to_destid(const char *s){
	dest_id id = DST_INVALID;
	if (s == NULL) {
		id = DST_NULL;
	}else if(strcmp(s, "M") == 0) {
		id = DST_M;
	}else if(strcmp(s, "D") == 0) {
		id = DST_D;
	}else if(strcmp(s, "MD") == 0) {
		id = DST_MD;
	}else if(strcmp(s, "A") == 0) {
		id = DST_A;
	}else if(strcmp(s, "AM") == 0) {
		id = DST_AM;
	}else if(strcmp(s, "AD") == 0) {
		id = DST_AD;
	}else if(strcmp(s, "AMD") == 0) {
		id = DST_AMD;
	}
	return id;	
}

static inline comp_id str_to_compid(const char *s, int *a){
	comp_id id = COMP_INVALID;
	if(strcmp(s, "0") == 0) {
		id = COMP_0;
		*a=0;
	}else if(strcmp(s, "1") == 0) {
		id = COMP_1;
		*a=0;
	}else if(strcmp(s, "-1") == 0) {
		id = COMP_Neg1;
		*a=0;
	}else if(strcmp(s, "D") == 0) {
		id = COMP_D;
		*a=0;
	}else if(strcmp(s, "A") == 0) {
		id = COMP_A;
		*a=0;
	}else if(strcmp(s, "!D") == 0) {
		id = COMP_NotD;
		*a=0;
	}else if(strcmp(s, "!A") == 0) {
		id = COMP_NotA;
		*a=0;
	}else if(strcmp(s, "-D") == 0) {
		id = COMP_NegD;
		*a=0;
	}else if(strcmp(s, "-A") == 0) {
		id = COMP_NegA;
		*a=0;
	}else if(strcmp(s, "D+1") == 0) {
		id = COMP_DPos1;
		*a=0;
	}else if(strcmp(s, "A+1") == 0) {
		id = COMP_APos1;
		*a=0;
	}else if(strcmp(s, "D-1") == 0) {
		id = COMP_DNeg1;
		*a=0;
	}else if(strcmp(s, "A-1") == 0) {
		id = COMP_ANeg1;
		*a=0;
	}else if(strcmp(s, "D+A") == 0) {
		id = COMP_DPosA;
		*a=0;
	}else if(strcmp(s, "D-A") == 0) {
		id = COMP_DNegA;
		*a=0;
	}else if(strcmp(s, "A-D") == 0) {
		id = COMP_ANegD;
		*a=0;
	}else if(strcmp(s, "D&A") == 0) {
		id = COMP_DAndA;
		*a=0;
	}else if(strcmp(s, "D|A") == 0) {
		id = COMP_DOrA;
		*a=0;
	}else if(strcmp(s, "M") == 0) {
		id = COMP_M;
		*a=1;
	}else if(strcmp(s, "!M") == 0) {
		id = COMP_NotM;
		*a=1;
	}else if(strcmp(s, "-M") == 0) {
		id = COMP_NegM;
		*a=1;
	}else if(strcmp(s, "M+1") == 0) {
		id = COMP_MPos1;
		*a=1;
	}else if(strcmp(s, "M-1") == 0) {
		id = COMP_MNeg1;
		*a=1;
	}else if(strcmp(s, "D+M") == 0) {
		id = COMP_DPosM;
		*a=1;
	}else if(strcmp(s, "D-M") == 0) {
		id = COMP_DNegM;
		*a=1;
	}else if(strcmp(s, "M-D") == 0) {
		id = COMP_MNegD;
		*a=1;
	}else if(strcmp(s, "D&M") == 0) {
		id = COMP_DAndM;
		*a=1;
	}else if(strcmp(s, "D|M") == 0) {
		id = COMP_DOrM;
		*a=1;
	}
	return id;
}

#endif












