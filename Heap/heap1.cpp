#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 200
struct h{
	int data[MAX_HEAP];
	int c;
};

h* initHeap(){
	h* newHeap = (h*)malloc(sizeof(h));
	newHeap->c = 0;
	return newHeap;
}

void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
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

void insert(h* r, int val){
	r->c++;
	r->data[r->c] = val;
	int idx = r->c;
	while(idx != 1){
		int pIdx = getParent(idx);
		if(r->data[idx] >= r->data[pIdx]){
			break;
		}
		swap(&r->data[idx] , &r->data[pIdx]);
		idx = pIdx;
	}
}

int findMin(h* c){
	return c->data[1];
}

void printHeap(h *root)
{
	printf("Heap: ");
	for(int i = 0 ; i < root->c ; i ++)
	{
		printf("%d ", root->data[i + 1]);
	}
	printf("\n");
}

void pop(h* r){
	r->data[1] = r->data[r->c];
	r->c--;
	
	int idx = 1;
	while(getLeft(idx) <= r->c){
		int idxLeft = getLeft(idx);
		int idxRight = getRight(idx);
		int idxMin = idxLeft;
		
		if(idxRight <= r->c && r->data[idxRight] < r->data[idxMin]){
			idxMin = idxRight;
		}
		if(r->data[idx] <= r->data[idxMin]){
			break;
		}
		swap(&r->data[idx], &r->data[idxMin]);
		idx = idxMin;
	}
}
int main(){
	h *priorityQueue = initHeap();
	insert(priorityQueue, 7);
	insert(priorityQueue, 5);
	insert(priorityQueue, 1);
	insert(priorityQueue, 0);
	printf("Min data in heap: %d\n" , findMin(priorityQueue));
	printHeap(priorityQueue);
	return 0;
}
