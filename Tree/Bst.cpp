#include <stdio.h>
#include <malloc.h>

//1. struct node.
//2. insert: BC, recur
//3. traversal
//4. find recur & delete

struct node
{
	int key;
	node *left, *right;	
};

void insert(node**curr, int key)
{
	if(*curr == NULL)
	{
		*curr = (node*)malloc(sizeof(node)); //jika node saat ini kosong
		(*curr)->key=key;
		(*curr)->left = (*curr)->right = NULL;
		return;
	}
	if(key < (*curr)->key) //pindah ke anak kiri
	{
		insert(&(*curr)->left, key);
		return;
	}
	if(key > (*curr)->key) //pindah ke anak kanan
	{
		insert(&(*curr)->right, key);
		return;
	}
	
}

void preOrder(node *curr)
{
	if(curr != NULL)
	{
		printf("%d ", curr->key);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(node *curr)
{
	if(curr != NULL)
	{
		inOrder(curr->left);
		printf("%d ", curr->key);
		inOrder(curr->right);
	}
}

void postOrder(node *curr)
{
	if(curr != NULL)
	{
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ", curr->key);
		
	}
}

node* find(node *curr, int key)
{
	if(curr == NULL || curr->key == key)
	{
		return curr;
	}
	if(key < curr->key )
	{
		return find(curr->left, key);
	}
	else if(key > curr->key)
	{
		return find(curr->right, key);
	}
}

node* findRightMost(node *curr) //untuk predecessor, if successor the find left most
{
	while(curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr;
}
void deleteNode(node **curr, int key)
{
	if(*curr == NULL) //tidak ketemu 
	{
		return;
	}
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
	//case 1: tidak ketemu child
	if((*curr)->left == NULL && (*curr)->right == NULL)
	{
		free(*curr);
		*curr = NULL;
		return;
	}
	//case 2: only left child
	if((*curr)->right == NULL)
	{
		(*curr)->key = (*curr)->left->key;
		deleteNode(&(*curr)->left, (*curr)->key);
		return;
	}
	if((*curr)->left == NULL) //jika ada anak kanan
	{
		(*curr)->key = (*curr)->right->key;
		deleteNode(&(*curr)->right, (*curr)->key);
		return;
	}
	
	//case 3: ada dua child
	node *predecessor = findRightMost((*curr)->left);
	(*curr)->key = predecessor->key;
	deleteNode(&(*curr)->left, predecessor->key);
}

int main()
{
	node *root = NULL;
	insert(&root, 10);
	insert(&root, 5);
	insert(&root, 7);
	insert(&root, 20);
	insert(&root, 17);
	deleteNode(&root, 10);
	
	printf("Preorder: ");
	preOrder(root);
	printf("\n");
	
	printf("Inorder: ");
	inOrder(root);
	printf("\n");
	
	printf("Postorder: ");
	postOrder(root);
	printf("\n");
	
	node *result = find(root, 7);
	if(result)
	{
		printf("Result: %d\n", result->key);
	}
	else
	{
		printf("Not found\n");
	}
	
	return 0;
}
