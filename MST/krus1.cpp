#include <stdio.h>
#include <stdlib.h>
#define Vertices 8

//define edge, subset, compareedge
//findparent(if subsets[i].parent != i
//joinset(root xy, if x rank < y rank , > , else rank++)

//kruskal (declare result array, i ,e , qsort, subsets)
//init i.parent and rank, while i < total && e < v - 1:
//nx edge i++, x.src y.dest, res e++ & joinset, print

struct Edge
{
	int src, dest, weight;
};

struct Subset
{
	int parent, rank;	
};

int findParent(Subset subsets[], int i)
{
	if(subsets[i].parent != i)
	{
		subsets[i].parent = findParent(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

int compareEdge(const void *a, const void *b)
{
	return ((Edge*)a)->weight - ((Edge*)b)->weight; 
}

void joinSet(Subset subsets[], int x, int y)
{
	int rootX = findParent(subsets, x);
	int rootY = findParent(subsets, y);
	
	if(subsets[rootX].rank < subsets[rootY].rank)
	{
		subsets[rootX].parent = y;
	}
	else if(subsets[rootX].rank > subsets[rootY].rank)
	{
		subsets[rootY].parent = x;
	}
	else
	{
		subsets[rootY].parent = x;
		subsets[rootX].rank++;
	}
}

void kruskal(Edge edges[], int totalEdge)
{
	//declare part
	Edge result[Vertices - 1];
	int i = 0;
	int e = 0;
	qsort(edges, totalEdge, sizeof(edges[0]), compareEdge);
	Subset subsets[Vertices];
	//
	
	for(int i = 0 ; i < Vertices ; i ++ )
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	//itung brp edge yg udah di iterasi
	while(i < totalEdge && e < Vertices -1)
	{
		Edge nextEdge = edges[i++];
		int x = findParent(subsets, nextEdge.src);
		int y = findParent(subsets, nextEdge.dest);
		if(x != y)
		{
			result[e++] = nextEdge;
			joinSet(subsets, x, y);
		}
	}
	//
	
	for(int i = 0; i< Vertices - 1; i++)
	{
		printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
	}
}

int main()
{
	struct Edge edges[] = {
		// src dest, cost, src dest cost 
        {0, 1, 2}, {0, 3, 6}, 
        {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7}, {2, 5, 3},
        {3, 4, 9}, 
        {4, 5, 4}, {4, 6, 2},
        {5, 6, 6}, {5, 7, 1}, 
        {6, 7, 7} 
    };
    
    int totalEdges = sizeof(edges) / sizeof(edges[0]);
    kruskal(edges, totalEdges);
	return 0;
}
