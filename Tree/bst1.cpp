#include <stdio.h>
#include <stdlib.h>

//1. struct node.
//2. insert: BC, recur
//3. traversal
//4. find recur & delete

struct node
{
	int key;
	node *left, *right;	
};

void insert(node** curr, int key){
	if(*curr == NULL){
		node* newN = (node*)malloc(sizeof(node));
		newN->key = key;
		newN->left = newN->right = NULL;
	}
	else if(key < (*curr)->key){
		insert(&(*curr)->left, key);
	}
	else if(key > (*curr)->key){
		insert(&(*curr)->right, key);
	}
}

node** find(node** curr, int key){
	if(!*curr)return curr;
	if((*curr)->key == key)return curr;
	else if(key < (*curr)->key ){
		return find(&(*curr)->left, key);
	}
	else if(key > (*curr)->key){
		return find(&(*curr)->right, key);
	}
}

node** findRightMost(node** c){
	while(*c && (*c)->right != NULL){
		*c = (*c)->right;
	}
	return c;
}

void deleteNode(node** curr, int key){
	if(*curr == NULL)return;
	if(key < (*curr)->key)
    {
        deleteNode(&(*curr)->left, key);
        return;
    }
    if(key > (*curr)->key)
    {
        deleteNode(&(*curr)->right, key);
        return;
    }
    
    // Case 1: No children
    if((*curr)->left == NULL && (*curr)->right == NULL){
    	free(*curr);
    	*curr = NULL;
    	return;
	}
	//case 2: left child
	if((*curr)->left == NULL){
		(*curr)->key = (*curr)->left->key;
		deleteNode(&(*curr)->left, (*curr)->key);
		return;
	}
	//case 3 right child
	
	//case 4: two children
	node **prede = findRightMost(&(*curr)->left);
	(*curr)->key = (*prede)->key;
	deleteNode(&(*curr)->left, (*prede)->key);
    
}
void preOrder(node* r){
	if(!r){
		printf("%d", r->key);
		preOrder(r->left);
		preOrder(r->right);
	}
}

int main(){
	node *root = NULL;
	return 0;
}
