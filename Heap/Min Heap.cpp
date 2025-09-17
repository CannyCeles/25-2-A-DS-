#include <stdio.h>
#include <malloc.h>
#define MAX_HEAP 100

struct heap
{
	int data[MAX_HEAP];
	int curr;			
};

heap *initHeap()
{
	heap *newHeap = (heap*)malloc(sizeof(heap));
	newHeap->curr = 0;
	return newHeap;
}

int getParent(int x)
{
	return x / 2;
}

int getLeft(int x)
{
	return x * 2;
}

int getRight(int x)
{
	return x * 2 + 1;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void push(heap *root, int value)
{
	root->curr++;
	root->data[root->curr] = value;
	
	//upHeap
	int idx = root->curr;
	while(idx != 1) //selama belum sampai root
	{
		int parentIdx = getParent(idx);
		if(root->data[idx] >= root->data[parentIdx])
		{
			break;
		}
		swap(&root->data[idx], &root->data[parentIdx]);
		idx = parentIdx;
	}
}

int findMin(heap *root)
{
	return root->data[1];
}

void printHeap(heap *root)
{
	printf("Heap: ");
	for(int i = 0 ; i < root->curr ; i ++)
	{
		printf("%d ", root->data[i + 1]);
	}
	printf("\n");
}
void pop(heap *root)
{
	root->data[1] = root->data[root->curr];
	root->curr--;
	
	//downHeap
	int idx = 1;
	while(getLeft(idx) <= root->curr) //loop selama belum di leaf
	{
		int idxLeft = getLeft(idx);
		int idxRight = getRight(idx);
		int idxMin = idxLeft;
		//check if idx saat ini ada anak kanan
		if(idxRight <= root->curr && root->data[idxRight] < root->data[idxMin])
		{
			idxMin = idxRight;			
		}
		if(root->data[idx] <= root->data[idxMin])
		{
			break;
		}		
		swap(&root->data[idx], &root->data[idxMin]);
		idx = idxMin;
		
	}
}
int main()
{
	heap *priorityQueue = initHeap();
	push(priorityQueue, 7);
	push(priorityQueue, 5);
	push(priorityQueue, 1);
	push(priorityQueue, 0);
//	pop(priorityQueue);
//	pop(priorityQueue);
//	pop(priorityQueue);
	
	printf("Min data in heap: %d\n" , findMin(priorityQueue));
	printHeap(priorityQueue);
	return 0;
}
