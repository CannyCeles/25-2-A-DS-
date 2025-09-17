#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int memo[1000];
void init(){
	for(int i = 0 ; i < 1000 ; i ++){
		memo[i] = -1;
	}
}

int findMin(int a , int b)
{
	return a < b ? a : b;
}
int coinChangeMemo(int *coins, int value, int size){
	init();
	if(value == 0)return 0;
	else if(value < 0)return INF;
	else if(memo[value] != -1)return memo[value];
	
	int minCoins = INF;
	for(int i = 0 ; i < size ; i ++)
	{
		int res = coinChangeMemo(coins, value - coins[i], size);
		if(res != INF)
		{
			minCoins = findMin(res+1 , minCoins);
		}
	}
	memo[value] = minCoins;
	return minCoins;
}

int coinChangeTabu(int *coins, int value, int size)
{
	int dp[value+1];
	dp[0] = 0;
	for(int i = 1 ; i <= value ; i ++)
	{
		dp[i] = INF;
	}
	for(int i = 1 ; i <= value ; i ++)
	{
		for(int j = 0 ; j < size ; j ++)
		{
			if(coins[j] <= i)
			{
				int subres = dp[i - coins[j]];
				if(subres != INF)
				{
					int res = findMin(dp[i], subres+1);
					dp[i] = res;
				}
			}
		}
	}
	return dp[value];
}

int main(){
	int coins[] = {1,3,4};
	int value = 6;
	
	int size = sizeof(coins) / sizeof(coins[0]);
	int res = coinChangeMemo(coins,value, size);
	printf("%d\n", res);
	int res2 = coinChangeTabu(coins,value, size);
	printf("%d", res2);
	return 0;
}
