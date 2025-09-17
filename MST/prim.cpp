#include <stdio.h>
#include <limits.h>
#define V 8
//fucntion buat nyari smallest harga dari node yg divisit
int minIdx(int value[], bool visited[]){
	int min = INT_MAX;
	int index = 0;
	
	for(int i = 0; i < V; i++){
		if(!visited[i] && value[i] < min){
			min = value[i];
			index = i;
		}
	}
	return index;
}
//debug
void printPrim(int parent[], int graph[][V]){
	printf("Print prim: \n");
	for(int i = 0; i < V; i++){
		printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
	}
}

void printParent(int parent[]){
	for(int i = 0; i < V; i++){
		printf("%d\n", parent[i]);
	}
	
	
}

void prim(int graph[][V]){
	
	int parent[V];
	int value[V];
	bool visited[V]; //apakah node sudah divisit
	
	for(int i = 0; i < V; i++){
		value[i] = INT_MAX; //mau nyari yg plg kecil
		visited[i] = false;
	}
	
	visited[0] = true; //sudah dikunjungi
	parent[0] = -1; //ga punya parent
	
	for(int i = 0; i < V; i++){ //node mana paling kecil
		int idx = minIdx(value, visited); 
		visited[idx] = true; //sudah tau mau ke node mana
		for(int j = 0; j < V; j++){ //ngambil value node paling min
									//update nilai cost termurah
			if(graph[idx][j] && !visited[j] //jika bukan 0 dan blm divisit
			   && graph[idx][j] < value[j]){
				value[j] = graph[idx][j];
				parent[j] = idx;
			}
		}
	}
	
	printPrim(parent, graph);
}

int main(){
	
	int graph[V][V] = {
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
