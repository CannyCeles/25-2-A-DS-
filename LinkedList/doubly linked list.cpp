#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct student{
	char name[100];
	int score;
	student *next, *prev;
	
}*head = NULL, *tail = NULL;


student* createNode(char name[], int score){
	student *newNode = (student*)malloc(sizeof(student));
	newNode->score = score;
	strcpy(newNode->name, name);
	newNode->next = newNode->prev = NULL;
	
	return newNode;
}

void pushHead(char name[], int score){
	student *newNode =  createNode(name, score);
	
	if(head == NULL){
		head = tail = newNode;
		return;
	}
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	
}

void pushTail(char name[], int score){
	student *newNode =  createNode(name, score);
	
	if(head == NULL){
		head = tail = newNode; 
		return;
	}
	
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	
}

void popHead(){
	if(head == NULL)return;
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	
	head = head->next;
	free(head->prev);
	head->prev = NULL;
}

void popTail(){
	if(head == NULL)return;
	if(head == tail){
		free(head);
		head = tail = NULL;
	}
	
	tail = tail->prev;
	free(tail->next);
	tail->next = NULL;
}

student* searchNode(char name[]){
	student* curr = head;
	while(curr != NULL){
		if(strcmp(curr->name, name)==0)return curr;
		curr = curr->next;
	}
	
	return NULL;
}

void printAll(){
	student* curr = head;
	while(curr != NULL){
		printf("%s %d - > ", curr->name, curr->score);
		curr = curr->next;
	}
	printf("NULL\n");
}

void popMid(char name[]){
	student *searchResult = searchNode(name);
	if(searchResult == NULL)return;
	
	if(searchResult == head){//antara posisi data di head/data cuma 1
		popHead();
		return;
	}	
	
	if(searchResult == tail){//posisi di tail
		popTail();
		return;
	}
	
	//posisi data ditengah
	searchResult->next->prev = searchResult->prev;
	searchResult->prev->next = searchResult->next;
	
	free(searchResult);
}

void popAll(){
	while(head)popHead();
}
int main(){
	pushHead("Andi", 100);
	pushHead("Budi", 50);
	
	printAll();
	student* searchResult = searchNode("Andi");
	if(searchResult == NULL)printf("NOT FOUND\n");
	else printf("%s score is %d\n", searchResult->name, searchResult->score);
	
	
}

