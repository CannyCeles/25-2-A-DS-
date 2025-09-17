#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//untuk menyimpan data dinamis yang juga menyimpan data dinamis yg lain
//recursive

//1.declare 2 DLL outer inner, head tail
//2.struct* create function for both
//3.push inner: best case if outer empty.init array, if inner empty = create. else set pointers 
//4.push outer: if empty = create. init array, if empty create, else set pointers 
//5.search outer : struct*. BC empty. init array. while loop c->next
//6.push inner by outer: BC empty. init. if empty. apply no 3.

//7.print outer: BC empty. init outer. while not null = print. 
//init inner. BC empty. while not null = print. outer++ 

struct Matakuliah
{
    char name[50];
    Matakuliah *prev, *next;
};

struct Jurusan
{
    Matakuliah* mHead, *mTail;
    char name[50];
    Jurusan * prev, *next;
};

Matakuliah* createMatKul(char* name)
{
    Matakuliah* temp = (Matakuliah*)malloc(sizeof(Matakuliah));
    temp->next = temp->prev = NULL;
    strcpy(temp->name, name);
    return temp;
}

Jurusan* createJurusan(char* name)
{
    Jurusan* temp = (Jurusan*)malloc(sizeof(Jurusan));
    temp->next = temp->prev = NULL;
    temp->mHead = temp->mTail = NULL;
    strcpy(temp->name, name);
    return temp;
}

void pushMK(Jurusan* jCurr, char * mNama)
{
    if(!jCurr)return;
    Matakuliah * mCurr = createMatKul(mNama);
    
    if(!jCurr->mTail)
    {
        jCurr->mHead = jCurr->mTail = mCurr;
    }
    else
    {
        mCurr->prev = jCurr->mTail;
        jCurr->mHead->next = mCurr;
        jCurr->mTail = mCurr;
    }
}

void pushJurusan(Jurusan** jHead, Jurusan** jTail,  char * jNama)
{
    Jurusan* jCurr = createJurusan(jNama);
    if(!jHead)
    {
        *jHead = *jTail = jCurr;
    }
    else
    {
        jCurr->prev = *jTail;
        (*jTail)->next = jCurr;
        *jTail = jCurr;
    }
}

Jurusan* searchJurusan(Jurusan *jHead, char* jNama)
{
    if(!jHead)
    {
        printf("Tidak ada\n");
        return NULL;
    }
    Jurusan *c = jHead;
    while(c)
    {
        if(strcmp(c->name, jNama) == 0)
        {
            return c;
        }
        c = c->next;
    }
    return 0;
}

void pushMKbyJurusan(Jurusan** jhead, char *jNama, char *mNama)
{
    if(!*jhead)
    {
        printf("tidak ada data jurusan\n");
        return;
    }
    Jurusan * c = searchJurusan(*jhead, jNama);
    if(!c)
    {
        printf("nama jurusan not found\n");
        return;
    }
    pushMK(c, mNama);
}

void printJurusan(Jurusan* jH)
{
	if(!jH)
	{
		printf("tidak ada jurusan");
		return;
	}
	Jurusan* jC = jH;
	while(jC)
	{
		printf("Jurusan : %s", jC->name);
		Matakuliah* mC = jC->mHead;
		if(!mC)
		{
			printf("tidak ada matkul\n");
			return;
		}
		while(mC)
		{
			printf("- %s", mC->name);
			mC = mC->next;
		}
		printf("\n");
		jC = jC->next;
	}
}
int main()
{
    return 0;
}
