#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int maxVal(int a, int b){
	return a > b ? a : b;
}

int knapsackTabu(int weightMax, int* itemWeight, int* profit, int n){
	int dp[n+1][weightMax+1];
	
	for(int i = 0 ; i <= n ; i ++)
	{
		for(int w = 0 ; w <= weightMax ; w ++)	
		{
			if(w == 0 || i == 0){
				dp[i][w] = 0;
			}
			else if(itemWeight[i-1] <= w){
				dp[i][w] = maxVal(dp[i-1][w], profit[i-1] + dp[i-1][w-itemWeight[i-1]]);
			}
			else
			{
				dp[i][w] = dp[i-1][w];
			}
		}
	}
	return dp[n][weightMax];
}

int memo[1000][1000];

void init(){
	for(int i = 0 ; i < 1000; i ++)
	{
		for(int j = 0 ; j < 1000 ; j ++){
			memo[i][j] = -1;
		}
	}
}

int knapsackMemo(int weightMax, int* itemWeight, int* profit, int n)
{
	init();
	if(memo[n][weightMax] != - 1){
		return memo[n][weightMax];
	}
	
	int result = 0;
	
	if(n == 0 || weightMax == 0){
		result = 0;
	}
	else if(itemWeight[n-1] <= weightMax){
		result = maxVal(profit[n-1] + knapsackMemo(weightMax - itemWeight[n-1], itemWeight,
		profit, n-1), knapsackMemo(weightMax, itemWeight, profit, n - 1));
	}
	else
	{
		result = knapsackMemo(weightMax, itemWeight, profit, n - 1);
	}
	
	
	memo[n][weightMax] = result;
	return result; 
}
int main(){
	int itemWeight[] = {2, 3, 5};
	int Profit[] = {3, 4, 5};
	int weightMax = 5;
	int size = sizeof(itemWeight) /sizeof(itemWeight[0]);
	printf("%d\n", knapsackTabu(weightMax, itemWeight, Profit, size));
	printf("%d\n", knapsackMemo(weightMax, itemWeight, Profit, size));
	
	return 0;
}
