#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

#include <vector>
#include <queue>
#define LENGTH 10
#define WIDTH 18
#define INF INT_MAX

using namespace std;

//djikstra algo. 
//1. declare struct pos xy.struct map visit,pos,value,cost,*before. struct compare
//2. declare count, init map, pos. 
//3. Print map. dirX,dirY

//4. Djikstra(): PrioQ <M*, vecM*, compare>ListMap. LM.push(dMap[startPosY,startPosX)
// cMap. while LM!=. cM = lM.top. LM.pop.  if cMval = E, if visited. set isvisit to true 
//for i<4. newX&Y = cM->pos.x + dirX[i]. check out of bounds
// newMap = djnexYnewX. check newMapVal. conti. newCost = cMCost+1
//if newcost < newM->cost:newMcost = newcost. newMbefore = cMap.listmap.pushNewMap


struct Position{
	int x,y;
};

struct Map{
	char value;
	int cost;
	Position position;
	bool isVisited;
	Map* before;
};

struct compare{
	bool operator()(Map* a , Map* b)
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
Position endPos, startPos;

void initMap()
{
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
			djMap[i][j].cost = INF;
			djMap[i][j].before = NULL;
			djMap[i][j].isVisited = false;
			djMap[i][j].value = currChar;
			djMap[i][j].position = currPos;	
		}
	}
	djMap[startPos.y][startPos.x].cost = 0;
}

void printMap() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", djMap[i][j].value);
        }
        printf("\n");
    }
}

int dirX = {1,-1,0,0};
int dirY = {0,0,-1,1};

//4. Djikstra(): PrioQ <M*, vecM*, compare>ListMap. LM.push(dMap[startPosY,startPosX)
// cMap. while LM!=. init CM by LMtop LM.pop.  if cMval = E, if visited. 
//for i<4. newX&Y = cM->pos.x + dirX[i].
void djikstra()
{
	priority_queue<Map*, vector<Map*>, compare>listMap;
	listMap.push(&djMap[startPos.y][startPos.x]);
	Map* currMap;
	
	while(!listMap.empty())
	{
		currMap = listMap.top();
		listMap.pop();
		
		if(currMap->value == 'E')break;
		if(currMap->isVisited)continue;
		currMap->isVisited = true;
		
		for(int i = 0 ;  i < 4 ; i ++)
		{
			int newX = currMap->position.x + dirX[i];
			int newY = currMap->position.y + dirY[i];
			
			if(newX < 0 || newY < 0 || newX >= WIDTH || newY >= LENGTH)continue;
			
			Map* newMap = currMap[newY][newX];
			if(newMap->value == '#' || newMap->isVisited)continue;
			
			int newCost = currMap->cost +1;
			if(newCost < newMap->cost)
			{
				newMap->cost = newCost;
				newMap->before = currMap;
				listMap.push(newMap);
			}
		}
	}
}

int main()
{
	return 0;
}
