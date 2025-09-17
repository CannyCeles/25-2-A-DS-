#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int memo[1000];
void init()
{
	for(int i = 0 ; i < 1000 ; i ++)
	{
		memo[i] = -1;
	}
}

int fiboMemo(int n)
{
	init();
	if(n <= 1)return n;
	else if(memo[n] != -1)return memo[n];
	return memo[n] = fiboMemo(n-1) + fiboMemo(n-2);
}

int fiboTabu(int n)
{
	if(n<=1)return n;
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n ; i ++)
	{
		dp[i] = dp[i-1] + dp[i-2];	
	}	
	return dp[n];
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("Hasil Memo :%d\n", fiboMemo(n));
	printf("Hasil Tabu : %d\n", fiboTabu(n));
	return 0;
}
