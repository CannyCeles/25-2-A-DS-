#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABLE_SIZE 10

//1. hash function
//2. insert with sorted collision handling
//3. get value
//4. 
struct S{
	char name[20];
	int score;
	S* next;
};

S* hashTable[TABLE_SIZE];

int hash(char *name)
{
	int firstC = name[0];
	int hashN = firstC - 'A';
	return hashN % TABLE_SIZE;
}

void insert(char* name, int score){
	int hashNum = hash(name);
	S* data = (S*)malloc(sizeof(S));
	data->score = score;
	strcpy(data->name, name);
	data->next = NULL;
	
	int idx = hashNum;
	if(hashTable[idx] == NULL){
		hashTable[idx] = data;
		return ;
	}
	S* c = hashTable[idx];
	while(c->next != NULL){
		c = c->next;
	}
	c->next = data;
}

S* get(char* name)
{
	int hashN = hash(name);
	int idx = hashN;
	S* c = hashTable[idx];
	while(c){
		if(strcmp(c->name, name) == 0){
			return c;
		}
		c = c->next;
	}
	return NULL;
}

void unSet(char* name){
	int hashN = hash(name);
	int idx = hashN;
	S* c = hashTable[idx];
	if(c == NULL)return;
	
	//if at head
	if(strcmp(c->name, name) == 0){
		S* toFree = hashTable[idx];
		hashTable[idx] = hashTable[idx]->next;
		free(toFree);
		return;
	}
	while(c->next != NULL){
		if(strcmp(c->next->name, name ) == 0)
		{
			S* to_be_free = c->next;
			c->next = to_be_free->next;
			free(to_be_free);
			return;
		}	
		c = c->next;
	}
}
int main()
{
	return 0;
}
