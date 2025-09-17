#include <stdio.h>

int binarySearch(int arr[], int n, int target){
	int start = 0;
	int end = n - 1;
	while(start <= end){
		int mid = (start + end) /2;
		if(arr[mid] == target)return mid;
		else if(target > arr[mid]){
			start = mid + 1;
		}
		else{
			end = mid -1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {10, 15, 20, 23, 28, 35, 40};
	int n = sizeof(arr)/sizeof(arr[0]);
	int idx = binarySearch(arr, n, 28);
	printf("%d\n", idx+1);
	return 0;
}
