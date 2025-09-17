#include <stdio.h>
#include <stdlib.h>
#define V 8

struct Edge
{
	int src, dest, weight;
};

struct Subset
{
	int parent, rank;	
};

int findParent(Subset subset[], int i)
{
	if(subset[i].parent != i )
	{
		subset[i].parent = find(subset, subsets[i].parent);
	}
	return subset[i].parent;
}

void joinSet(Subset subset[], int x, int y)
{
	int rootX = findParent(subset, x);
	int rootY = findParent(subset, y);
	
//	//compare
//	if(subset[rootX].rank < subset[rootY].rank)
//	{
//		subset[rootX].parent = y;
//	} 
//	else if(subset[rootX].rank > subset[rootY].rank)
//	{
//		subset[rootY].parent = x;
//	}
//	else
//	{
//		subset[rootY].parent = x;
//		subset[rootX].rank++;
//	}

	if(subset[rootX].rank < subset[rootY].rank)
	{
		subset[rootX].parent = y;
	}
	else if(subset[rootX].rank > subset[rootY].rank)
	{
		subset[rootY].parent = x;
	}
	else
	{
		
	}
}

void kruskal()
{
	
}
int main()
{
	return 0;
}
