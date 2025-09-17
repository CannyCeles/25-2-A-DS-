#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

//1. array memo/tabu, findMin,initArray
//2. coinChangeMemo base case, mincoins , result coinchange()
//mincoins = findmin res, mincoins
//memo[value] mincoins return 
 
//3. coinChangeTabu
//declare tabu[value + 1], tabu[0], initTabu i = 1 <= value
//for i = 1 <= value + 1, j < size, if tabu j <= i : subRes = tabu[j - coins i]
//result = findmin tabu[i], subres.	tabu[i] = res 
//return tabu[value]

int memoize[10001];

int findMin(int a, int b)
{
	return a < b ? a : b;
}

void initMemo()
{
	for(int i = 0 ;i < 10001 ; i ++)
	{
		memoize[i] = -1;
	}
}
int coinChangeMemo(int * coins, int size, int value)
{
	if(value == 0)return 0;
	else if(value < 0)return INF;
	else if(memoize[value] != -1)return memoize[value];
	
	int minCoins = INF;
	for(int i = 0 ; i < size ; i ++)
	{
		int result = coinChangeMemo(coins, size, value - coins[i]);
		if(result != INF)
		{
			minCoins = findMin(result + 1, minCoins);
		}
	}
	memoize[value] = minCoins;
	return minCoins;
}

int coinChangeTabu(int * coins, int size, int value)
{
	int dp[value + 1]; 
	dp[0] = 0;
	for(int i = 1; i <= value ; i ++)
	{
		dp[i] = INF;
	}
	
	for(int i = 1 ; i <= value ; i ++)
	{
		for(int j = 0 ; j < size ; j ++)
		{
			if(dp[j] <= i)
			{
				int subRes = dp[i - coins[j]];
				if(subRes != INF)
				{
					int res = findMin(dp[i], subRes + 1);
					dp[i] = res;
				}
			}			
		}
	}
	return dp[value];
}

int main()
{
	int coins[] = {1,3,4};
	int size = sizeof(coins) / sizeof(coins[0]);
	int value = 6;
	
	initMemo();
	int res = coinChangeMemo(coins, size, value);
	printf("%d", res);
	
	return 0;
}
