#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
int memo[1001];

void initMemo()
{
	for(int i = 0 ;i < 5 ; i ++)
	{
		memo[i] = -1;
	}
}
int fibMemo(int n) 
{
	if(n <= 1)return n;
	else if(memo[n] != -1)return memo[n];
	memo[n] = fibMemo(n - 1) + fibMemo(n -2);
	return memo[n];
}

int fibTabu(int n)
{
	if(n <= 1)return n;
	int tabu[n + 1];
	tabu[0] = 0;
	tabu[1] = 1;
	for(int i = 2; i <= n ; i ++)
	{
		tabu[i] = tabu[i-1] + tabu[i-2];
	}
	return tabu[n];
}
int main()
{
	int n;
	scanf("%d", &n);
	initMemo();
	printf("Hasil Memo :%d\n", fibMemo(n));
	printf("Hasil Tabu : %d\n", fibTabu(n));
	return 0;
}
