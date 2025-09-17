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
struct Position {
    int x, y;
};

struct Map {
    char value;
    int cost;
    Position pos;
    bool visited;
    Map* before;
    double heu;
};

struct Compare {
    bool operator()(Map* a, Map* b) {
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

void init() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char currChar = mapChar[i][j];
            Position currPos;
            currPos.x = j;
            currPos.y = i;
            
            if (currChar == 'E') endPos = currPos;
            if (currChar == 'S') startPos = currPos;
            
            dMap[i][j].before = NULL;
            dMap[i][j].cost = INT_MAX;
            dMap[i][j].pos = currPos;
            dMap[i][j].value = currChar;
            dMap[i][j].visited = false;
            dMap[i][j].heu = abs(endPos.x - j) + abs(endPos.y - i);
            // Removed heuristic initialization
        }
    }
    dMap[startPos.y][startPos.x].cost = 0;
}

void printMap() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", dMap[i][j].value);
        }
        printf("\n");
    }
}

int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

void dijkstra() {
    // Priority queue sorted only by path cost
    priority_queue<Map*, vector<Map*>, Compare> listMap;
    listMap.push(&dMap[startPos.y][startPos.x]);
    Map* currMap;
    
    while (!listMap.empty()) {
        currMap = listMap.top();
        listMap.pop();
        
        if (currMap->value == 'E') break;
        if (currMap->visited) continue;
        
        currMap->visited = true;
        
        for (int i = 0; i < 4; i++) {
            int newX = currMap->pos.x + dirX[i];
            int newY = currMap->pos.y + dirY[i];
            
            // Check boundaries
            if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= LENGTH)
                continue;
                
            Map* newMap = &dMap[newY][newX];
            
            if (newMap->value == '#' || newMap->visited) continue;
            
            int newCost = currMap->cost + 1; // Each step costs 1
            
            if (newCost < newMap->cost) {
                newMap->cost = newCost;
                newMap->before = currMap;
                listMap.push(newMap);
            }
        }
    }
    
    // Mark the path
    while (currMap) {
        if (currMap->value != 'S' && currMap->value != 'E') {
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

int main() {
    init();
    dijkstra();
    return 0;
}
