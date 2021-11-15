#include "symtable.h"

int hash(char *str){
	unsigned long hash = 5381;
	int c;
	while(c = (*str++)){
		hash = ((hash << 5) + hash)	+ c;
	}
	return hash % SYMBOL_TABLE_SIZE;
}

struct Symbol *find(char * key){ 
	int hashIndex = hash(key);   
	while(hashArray[hashIndex] != NULL) {
	
		if(hashArray[hashIndex]->key == *key)
			return hashArray[hashIndex]; 
		++hashIndex;
		hashIndex %= SYMBOL_TABLE_SIZE;
   }        
	
   return NULL; 
}
void insert(char* key, hack_addr addr){
	struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol));
	item->addr = addr;  
	item->key = strdup(key);
	
	int hashIndex = hash(key);
	
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
		++hashIndex;
		hashIndex %= SYMBOL_TABLE_SIZE;
	}
	
   hashArray[hashIndex] = item;
}
void display_table(){

	for(int i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
		if(hashArray[i] != NULL)
			printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->addr);
		else
			printf(" ~~ ");
	}
	
	printf("\n");
}