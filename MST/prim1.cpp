#include <stdio.h>
#include <limits.h>
#define Vertices 8
#define INF INT_MAX

//1. idxMin(value, visit): declare min, index. i<V:if val[i] < min && !visit:
//min = value[i], index = i. return index  

//2. printPrim(*parent, graph[][v]), printParent
//3. prim(graph[][v]):val[],visit[],parent[]. init val & visit. val[0], parent[0]
//i<V: idx=idxMin. visit[] = true. f<V: if graph[idx][j] < value[j] & !visit[j] & exist:
//value[j] = grapph[idx][j]. parent[j] = idx. printPrim 


int minIdx(int * value, bool *visited)
{
	int min = INF;
	int index = 0;
	
	for(int i = 0 ; i < Vertices ; i ++)
	{
		if(value[i] < min && !visited[i])
		{
			min = value[i];
			index = i;
		}	
	}
	return index;
}

void printPrim(int * parent, int graph[][Vertices])
{
	for(int i = 0 ;i < Vertices ; i ++)
	{
		printf("%d - %d : %d\n", parent[i], i , graph[i][parent[i]]);
	}
}

void printParent(int * parent)
{
	for(int i = 0 ;i < Vertices ; i ++)
	{
		printf("%d", parent[i]);
	}
}

void prim(int graph[][Vertices])
{
	int parent[Vertices];
	int value[Vertices];
	bool visited[Vertices];
	
	for(int i = 0 ;  i < Vertices; i ++)
	{
		value[i] = INF;
		visited[i] = false;
	}
	
	parent[0] = -1;
	value[0]= 0;
	for(int i = 0 ;  i < Vertices; i ++)
	{
		int idx = minIdx(value, visited);
		visited[idx] = true;
		for(int j = 0 ; j < Vertices ; j ++)
		{
			if(graph[idx][j] && graph[idx][j] < value[j] && !visited[j])
			{
				value[j] = graph[idx][j];
				parent[j] = idx;	
			}	
		}	
	}
	printPrim(parent, graph);
}

int main()
{
	int graph[Vertices][Vertices] = {
        {0, 2, 0, 6, 0, 0, 0, 0},
        {2, 0, 3, 8, 5, 0, 0, 0},
        {0, 3, 0, 0, 7, 3, 0, 0},
        {6, 8, 0, 0, 9, 0, 0, 0},
        {0, 5, 7, 9, 0, 4, 2, 0},
        {0, 0, 3, 0, 4, 0, 6, 1},
        {0, 0, 0, 0, 2, 6, 0, 7},
        {0, 0, 0, 0, 0, 1, 7, 0}
    };
    prim(graph);
	return 0;
}
