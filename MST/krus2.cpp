#include <stdlib.h>
#include <stdio.h>
#define Vertices 8
//define edge, subset, compareedge
//findparent(if subsets[i].parent != i
//joinset(root xy, if x rank < y rank , > , else rank++)

//kruskal (declare result array, i ,e , qsort, subsets)
//init i.parent and rank, while i < total && e < v - 1:
//nx edge i++, x.src y.dest, res e++ & joinset, print

struct Edge
{
	int src,dest,weight;	
};

struct Subset
{
	int parent, rank;
};

int compareEdge(const void* a, const void* b)
{
	return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int findParent(Subset *subsets, int i)
{
	if(subsets[i].parent != i)
	{
		subsets[i].parent = findParent(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}
void joinSet(Subset *subsets, int x, int y)
{
	int rootX = findParent(subsets, x);
	int rootY = findParent(subsets, y);
	
	if(subsets[rootX].rank < subsets[rootY].rank)
	{
		subsets[rootX].rank = y;
	}
	else if(subsets[rootX].rank > subsets[rootY].rank)
	{
		subsets[rootY].rank = x;
	}
	else
	{
		subsets[rootY].rank = x;
		subsets[rootX].rank++; 
	}
}

void kruskal(Edge edges[], int totalEdges)
{
	Edge result[Vertices - 1];
	int i = 0; //brp edge yg kita sudah cek
	int e = 0; //edge yg sudah kita masukan ke dlm MST
	qsort(edges, totalEdges, sizeof(edges[0]), compareEdge);
	Subset subsets[Vertices];
	
	for(int i = 0 ; i < Vertices ; i ++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	
	while(i < totalEdges && e < Vertices - 1)
	{
		Edge nextEdge = edges[i++];
		int x = findParent(subsets, nextEdge.src);
		int y = findParent(subsets, nextEdge.dest);
		//detect cycle
		if(x != y)
		{
			result[e++]  = nextEdge;
			joinSet(subsets, x , y);
		}
	}
	
	for(int i = 0 ; i < Vertices - 1; i ++)
	{
		printf("result[i].src,weight,dest");
	}
}

int main()
{
	return 0;
}
