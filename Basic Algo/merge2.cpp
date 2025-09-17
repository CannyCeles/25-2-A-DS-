#include <stdio.h>

int merge(int *arr, int left , int mid, int right)
{
    int i = left;//left subarray
    int j = mid + 1;//right subarray
    int k = 0;//untuk index temp array
    int temp[right - left + 1];

    while(i <= mid && j<= right )
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
        while(i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while(j <= right)
        {
            temp[k++] = arr[j++];
        }
       for(int p = 0; p<k; p++)
        {
            arr[left + p] = temp[p];
        }
    }

    
}
int mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    return 0;
}