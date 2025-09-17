#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//MEMOIZATION

int memoize[10001];

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}

void initMemo()
{
	for(int i = 0 ; i < 1001 ; i ++)
	{
		memoize[i] = -1;
	}
}

int coinsChange(int* coins, int n, int amount)
{
	if(amount == 0){
		return 0;
	}
	if(amount < 0){
		return INT_MAX;
	}
	if(memoize[amount] != -1)
	{
		return memoize[amount];
	}
	
	int minCoins = INT_MAX;
	for(int i = 0 ; i < n ; i ++)
	{
		int res = coinsChange(coins, n, amount - coins[i]);	
		if(res != INT_MAX)
		{
			minCoins = min(res + 1, minCoins);	
		}		
	}
	memoize[amount] = minCoins;
	return memoize[amount];
}


int main()
{
	int coins[] = {1,3,4};
	int size = sizeof(coins) / sizeof(coins[0]);
	int amount = 6;
	
	initMemo();
	int memo = coinsChange(coins, size, amount);
	printf("%d", memo);
	
	return 0;
}
