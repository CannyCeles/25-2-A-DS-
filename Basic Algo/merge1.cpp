#include <stdio.h>

//searchTime + O(n log n)
//faster but uses more space O(n) than bubble, insert O(1), etc
void merge(int * arr, int left,int mid, int right){
	int i = left; //left subarray
	int j = mid + 1; //right subarray
	int k = 0; //temp array idx
	int temp[right - left + 1];
	
	while(i <= mid && j <= right){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid ){
		temp[k++] = arr[i++];
	}	
	while(j <= right){
		temp[k++] = arr[j++];
	}
	for(int p = 0; p < k ; p ++){
		arr[left + p] = temp[p];
	}
}

void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = (left+right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main(){
	int arr[] = {5, 3, 4, 9, 10};
	int size = sizeof(arr) / sizeof(arr[0]); 
	
	mergeSort(arr, 0, size - 1);
	for(int i = 0 ; i < size ; i ++){
		printf("%d ", arr[i]);
	}
	return 0;
}
