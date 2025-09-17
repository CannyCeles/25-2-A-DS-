#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n{
	char name[101];
	n* prev, *next;
}*tail = NULL, *head = NULL;

n* createN(char * name){
	n* newn = (n*)malloc(sizeof(n));
	strcpy(newn->name, name);
	newn->next = newn->prev = NULL;
	return newn;
}

void pushList(n** head, n** tail, char *name){
	n* newn = createN(name);
	if(*head == NULL){
		*head = *tail = newn;
		return;
	}
	
	if(strcmp(name, (*head)->name) < 0){
		(*head)->prev = newn;
		newn->next = *head;
		*head = newn;
		return;
	}
	n *c = *head;
	while(c->next && strcmp(name, c->next->name) > 0){
		c = c->next;
	}
	
	if(!c->next){
		(*tail)->next = newn;
		newn->prev = *tail;
		*tail = newn;
		return;
	}
	else{ //push mid + sorting
		newn->prev = c;
		newn->next = c->next;
		c->next->prev = newn;
		c->next = newn;
	}
}

n* searchList(n* h,char* name){
	n* c = h;
	while(c){
		if(strcmp(name, c->name) == 0){
			return c;
		}
		c = c->next;
	}
	return NULL;
}
void popList(n** head, n** tail, char* name) {
    if (*head == NULL) return; // List is empty

    n* curr = *head;

    // Search for the node with the matching name
    while (curr && strcmp(curr->name, name) != 0) {
        curr = curr->next;
    }

    if (curr == NULL) return; // Name not found

    // Case 1: Removing the only node
    if (*head == *tail && curr == *head) {
        *head = *tail = NULL;
    }
    // Case 2: Removing head
    else if (curr == *head) {
        *head = curr->next;
        (*head)->prev = NULL;
    }
    // Case 3: Removing tail
    else if (curr == *tail) {
        *tail = curr->prev;
        (*tail)->next = NULL;
    }
    // Case 4: Removing from the middle
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    free(curr);
}
int main(){
	return 0;
}
