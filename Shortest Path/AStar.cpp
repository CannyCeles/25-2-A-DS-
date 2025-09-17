#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#include <vector>
#include <queue>


#define LENGTH 10
#define WIDTH 18

using namespace std;


struct Position{
	int x, y;
};

struct Map{
	char value;
	int cost;
	Position pos;
	bool visited;
	double heu;
	Map* before;
};

struct Compare{
	bool operator()(Map *a, Map *b){
		return (a->cost + a->heu) > (b->cost + b->heu);
	}
};
int count = 0; 
char mapChar[LENGTH][WIDTH] = {
	"#################",
	"#E              #",
	"#               #",
	"#               #",
	"###  ##  ####   #",
	"#               #",
	"#### ###      ###",
	"####   ###    ###",
	"####           S#",
	"#################",
};

Map dMap[LENGTH][WIDTH];
Position endPos, startPos;

void init(){
	for(int i = 0 ; i < LENGTH ; i++){
		for(int j = 0 ; j < WIDTH ; j++){
			char currChar = mapChar[i][j];
			Position currPos;
			currPos.x = j;
			currPos.y = i;
			
			if(currChar == 'E') endPos = currPos;
			if(currChar == 'S') startPos = currPos;
			
			dMap[i][j].before = NULL;
			dMap[i][j].cost = INT_MAX;
			dMap[i][j].pos = currPos;
			dMap[i][j].heu = sqrt(pow(j - endPos.x , 2) + pow(i - endPos.y , 2));
			dMap[i][j].value = currChar;
			dMap[i][j].visited = false;
		}
	}
	dMap[startPos.y][startPos.x].cost = 0;
}

void printMap(){
	for(int i = 0 ; i < LENGTH ; i++){
		for(int j = 0 ; j < WIDTH ; j++){
			printf("%c", dMap[i][j].value);
		}
		printf("\n");
	}
}
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,-1,1};
void djikstra(){
	priority_queue<Map*, vector<Map*>, Compare> listMap;
	listMap.push(&dMap[startPos.y][startPos.x]);
	Map* currMap;
	while(!listMap.empty()){
		currMap = listMap.top();
		listMap.pop();
		
		if(currMap->value == 'E') break;
		currMap->visited = true;
		
		for(int i = 0 ; i < 4 ; i++){
			int newX = currMap->pos.x + dirX[i];
			int newY = currMap->pos.y + dirY[i];
			
			Map* newMap = &dMap[newY][newX];
			
			if(newMap->value == '#' || newMap->visited) continue;
			
			int newCost = currMap->cost;
			
			if(newCost < newMap->cost){
				newMap->cost = newCost;
				newMap->before = currMap;
				listMap.push(newMap);
			}
			
		}
	}
	while(currMap){
		if(currMap->value != 'S' && currMap->value != 'E'){
			system("cls");
			Sleep(50);
			currMap->value = '*';
						count++;
			printf("Count = %d", count);
			printMap();
		}
		currMap = currMap->before;
	}
}


int main(){
	init();
	djikstra();
}






