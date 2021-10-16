#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 200
#define MAX_LIMIT 100

int main(int argc, const char *argv[]) {
	if(argc != 2){
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fin = fopen( argv[1], "r" );
	if(fin == NULL){
		perror("Unable to open file!");
		exit(EXIT_FAILURE);
	}
	char out_file[MAX_LIMIT];
	strcpy(out_file, argv[0]);
	strcat(out_file, ".echo");
	FILE *fout = fopen(out_file, "w+");
	char line[MAX_LINE_LENGTH] = {0};
	unsigned int line_num = 0;
	while (fgets(line, sizeof(line), fin)){
		line_num = line_num + 1;
		printf("[%04d] %s", line_num, line);
		fprintf(fout, line);
	}
	fclose(fin);
	fclose(fout);
} 
