#include <stdio.h>
#include <stdlib.h>
#define Vertices 8

#define INF INT_MAX

struct Edge{
	int src,dest,weight;
};

struct Subset{
	int rank,parent;
};

int compareEdge(const void* a, const void* b){
	return ((Edge*)a)->weight - ((Edge*)b)->weight;
};
int findParent(Subset subsets[], int i){
	if(subsets[i].parent != i){
		subsets[i].parent = findParent(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}
void joinSet(Subset subsets[], int x, int y){
	int rootX= findParent(subsets, x);
	int rootY= findParent(subsets, y);
	
	if(subsets[rootX].rank < subsets[rootY].rank){
		subsets[rootX].rank = y;
	}
	else if(subsets[rootX].rank > subsets[rootY].rank){
		subsets[rootY].rank = x;
	}
	else
	{
		subsets[rootY].rank = x;
		subsets[rootX].rank++;
	}
}
void kruskal(Edge edges[], int totalEdges){
	Edge result[Vertices - 1];
	int i = 0 ;
	int e = 0 ;
	qsort(edges, totalEdges, sizeof(edges[0]), compareEdge);
	Subset subsets[Vertices];
	
	for(int i = 0  ; i < Vertices ; i ++){
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	while(i < totalEdges && e < Vertices - 1){
		Edge nextEdge = edges[i++];
		
		int x = findParent(subsets, nextEdge.src);
		int y = findParent(subsets, nextEdge.dest);
		if(x != y){
			res[e++] = nextEdge;
			joinSet(subset, x, y);
		}
	}
	
	for(int i = 0; i < Vertices - 1 ; i ++)
}
int main(){
	return 0;
}
