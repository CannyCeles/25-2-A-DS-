#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. declare struct with direction fields, root = null
//2. struct* create
//3. push all direction fields: init new, create. if exist.  set pointers.
//4. join LL direction fields: s* dir, s* dir. init up->down = down, vice versa

//5. view(s, lvl, maxlvl): if root. BC empty. if visited||lv >= maxLv return
//visited = true. recur all directions. view(s->dir, lv+1, maxLv) 
//6.recusrive neutralize: if !visited. esle set false. recusrion.

struct Station 
{
    char name[51];
    bool isVisited;
    Station *up, *down, *left, *right;
}*root=NULL;

Station * createStation(const char *name)
{
    Station* newStation = (Station*)malloc(sizeof(Station));
    strcpy(newStation->name, name);
    newStation->isVisited = false;
    newStation->up = newStation->down = newStation->left = newStation->right = NULL;
    return newStation;
}

void pushUp(Station* root, char* name)
{
    Station* newStation = createStation(name);
    if(root->up)
    {
        printf("Statioon already exists north %s\n", root->name);
        return;
    }
    root->up = newStation;
    newStation->down = root;
}

void pushDown(Station* root, char* name)
{
    Station* newStation = createStation(name);
    if(root->down)
    {
        printf("Statioon already exists south %s\n", root->name);
        return;
    }
    root->down = newStation;
    newStation->up = root;
}

void pushLeft(Station* root, char* name)
{
    Station* newStation = createStation(name);
    if(root->left)
    {
        printf("Statioon already exists west %s\n", root->name);
        return;
    }
    root->left = newStation;
    newStation->right = root;
}

void pushRight(Station* root, char* name)
{
    Station* newStation = createStation(name);
    if(root->right)
    {
        printf("Statioon already exists east %s\n", root->name);
        return;
    }
    root->right = newStation;
    newStation->left = root;
}

void joinNorthSouth(Station *up, Station* down)
{
    up->down = down;
    down->up = up;
}

void joinWestEast(Station* left, Station* right){
    left->right = right;
    right->left = left;
}

void view(Station* station, int level, int maxLevel)
{
    if(level == 0)printf("Stasiun: ");
    else if(station == NULL)
    {
        printf("tidak ada \n");
        return;
    }

    printf("%s", station->name);
    if(level >= maxLevel || station->isVisited)return;
    station->isVisited = true;

    for(int i = 0 ; i <= level; i ++)printf("-");
    printf("West: ");
    view(station->right, level + 1, maxLevel);

    for(int i = 0 ; i <= level; i ++)printf("-");
    printf("West: ");
    view(station->right, level + 1, maxLevel);

    for(int i = 0 ; i <= level; i ++)printf("-");
    printf("West: ");
    view(station->right, level + 1, maxLevel);

    for(int i = 0 ; i <= level; i ++)printf("-");
    printf("West: ");
    view(station->right, level + 1, maxLevel);
}

//neutralize everytime before calling view function
void neutralize(Station * temp)
{
    if(!temp->isVisited) return;
    temp->isVisited = false;
    neutralize(temp->right);
    neutralize(temp->right);
    neutralize(temp->right);
    neutralize(temp->right);
}

int main()
{
	root = createStation("Central Station");
    return 0;
}
