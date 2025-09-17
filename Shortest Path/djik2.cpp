#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <queue>
#include <vector>

#define LENGTH 10
#define WIDTH 18
#define INF INT_MAX

using namespace std;
struct Position{
	int x, y;
};
struct Map{
	int cost;
	bool visited;
	char value;
	Map* before;
	Position pos;
};

struct Compare{
	bool operator()(Map* a, Map* b)
	{
		return a->cost > b->cost;
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

Map djMap[LENGTH][WIDTH];
Position startPos, endPos;

void init(){
	for(int i = 0 ; i < LENGTH ; i ++)
	{
		for(int j = 0 ; j < WIDTH ; j ++)
		{
			char currChar = mapChar[i][j];
			Position currPos;
			currPos.x = j;
			currPos.y = i;
			
			if(currChar == 'S') startPos = currPos;
			if(currChar == 'E') endPos = currPos;
			djMap[i][j].value = currChar;
			djMap[i][j].pos = currPos;
			djMap[i][j].visited = false;
			djMap[i][j].cost = INF;
			djMap[i][j].before = NULL;
		}
	}
	djMap[startPos.y][startPos.x].cost = 0;
}

void printMap()
{
	for(int i = 0 ; i < LENGTH ; i ++)
	{
		for(int j = 0 ; j < WIDTH ; j ++)
		{
			printf("%c", djMap[i][j].value);	
		}
		
		printf("\n");
	}
}

int dirX[4]  = {1,-1,0,0};
int dirY[4]  = {0,0,-1,1};

void djikstra()
{
	priority_queue<Map*, vector<Map*>, Compare>listMap;
	listMap.push(&djMap[startPos.y][startPos.x]);
	Map * currMap;
	while(!listMap.empty()){
		currMap = listMap.top();
		listMap.pop();
		
		if(currMap->value == 'E')break;
		if(currMap->visited)continue;
		currMap->visited = true;
		
		for(int i = 0 ; i < 4; i ++){
			int newX = currMap->pos.x + dirX[i];
			int newY = currMap->pos.y + dirY[i];
			Map* newMap = &djMap[newY][newX];	
			
			if(newX < 0 || newX >= WIDTH || newY < 0 || newY >= LENGTH)continue;
			if(newMap->value == '#' || newMap->visited)continue;
			
			int newCost = currMap->cost + 1;
			if(newCost < newMap->cost){
				newMap->cost = newCost;
				newMap->before = currMap;
				listMap.push(newMap);
			}
		}	
	}
	//mark
	while(currMap){
		if(currMap->value != 'S' && currMap->value != 'E'){
			system("cls");
			Sleep(50);
			currMap->value = '*';
			count++;
			printf("%d", count);
			printMap();
		}
		currMap = currMap->before;
	}
}

int main()
{
	init();
	djikstra();

	return 0;
}
