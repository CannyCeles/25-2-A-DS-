#include <stdio.h>
 
int max(int a, int b){
	return a > b ? a : b;
} 

int knapsackTabulation(int weightMax, int *itemWeight, int *itemProfit, int n){
	int dp[n+1][weightMax+1];
	for(int i = 0 ; i <= n ; i ++)
	{
		for(int w = 0 ; w <= weightMax ; w++)
		{
			if(i == 0 || w ==0){
				dp[i][w] = 0;
			}
			else if(itemWeight[i - 1] <= w){
				dp[i][w] = max(itemProfit[i-1]+ dp[i-1][w - itemWeight[i-1]],dp[i-1][w]);
			}	
			else{
				dp[i][w] = dp[i-1][w]; 
			}
		}
	}
	return dp[n][weightMax];
}

int memo[100][100];
void init(){
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			memo[i][j] = -1;
		}
	}
}

int knapsackMemoization(int weightMax, int * itemWeight, int* itemProfit, int n){
	init();
	if(memo[n][weightMax] != -1){
		return memo[n][weightMax];
	}
	int result = 0;
	if(weightMax == 0 || n == 0)
	{
		result = 0;
	}
	else if(itemWeight[n - 1] <= weightMax)
	{
		result = max(itemProfit[n - 1] + knapsackMemoization(weightMax - itemWeight[n - 1], itemWeight, itemProfit, n - 1)
		,knapsackMemoization(weightMax, itemWeight, itemProfit, n - 1));
	}
	else
	{
		result = knapsackMemoization(weightMax, itemWeight, itemProfit, n - 1);
	}
	memo[n][weightMax] = result; 
	return result;
}
int main(){
	int itemWeight[] = {2, 3, 5};
	int itemProfit[] = {3, 4, 5};
	int weightMax = 5;
	int n = sizeof(itemWeight) / sizeof(itemWeight[0]);
	
	printf("%d\n", knapsackTabulation(weightMax, itemWeight, itemProfit, n));
	printf("%d\n", knapsackMemoization(weightMax, itemWeight, itemProfit, n));
	return 0;
}
