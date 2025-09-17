#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 100

int parent[MAX_SIZE];
int rank[MAX_SIZE];

void makeSet(int x)
{
	parent[x] = x;
	rank[x] = 0;
}

void initSet()
{
	for(int i = 0 ; i < MAX_SIZE; i ++)
	{
		makeSet(i);
	}
}

//find rep of element in set
int findSet(int x)
{
	//representative
	if(parent[x] == x)return x;
	//path compression : return parent[x] = findSet(parent[x]);
	return findSet(parent[x]);
}

void unionSet(int x, int y)
{
	int repX = findSet(x);
	int repY = findSet(y);
	
	if(rank[repX] < rank[repY])
	{
		parent[repX] = repY;	
	}
	else if(rank[repX] > rank[repY])
	{
		parent[repY] = repX;
	}
	else //equal rank
	{
		parent[repX] = repY;
		rank[repY]++;
	}
	
}

bool isConnected(int x, int y)
{
	int repX = findSet(x);
	int repY = findSet(y);
	
	return repX == repY;
}

void printPath(int x)
{
	printf("%d => ", x);
	if(parent[x] == x)return;
	printPath(parent[x]);
}
int main()
{
	initSet();	
	
	unionSet(1, 2);
	unionSet(2, 3);
	unionSet(5, 4);
	unionSet(4, 1);
	unionSet(8, 3);
	
	
	
	printf("Print path:");
	printPath(5);
	printf("\n");
	if(isConnected(2,5))printf("Connected!\n");
	else printf("Disconnected!\n");
	
	return 0;
}
