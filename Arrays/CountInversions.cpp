//swapping adjacent integers using inversion count to store the maximum cost of swap so far.
//similar to inversion count which can used to find min swaps to sort an array only adjacent swaps allowed.
#include <iostream>
#include <stdlib.h>
using namespace std;
//O(nLog(n)) time O(n) space
int merging(int arr[],int l,int mid,int h){
    int k = 0, i = l, j = mid+1;
    int temp[h - l + 1];
    int c = 0;
    while(i <= mid && j <= h){
        if(arr[i]<=arr[j]) //no swap required for higher val
        {
            temp[k++] = arr[i++];
        }
        else{
            //swap took place and out of all mid-i+1 swap with mid would be maximum
            c = c + (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= h){
        temp[k++] = arr[j++];
    }

    //update the initial array with temp array 0th indexing i-l is required
    for(int i = l; i <= h; i++){
        arr[i] = temp[i-l];
    }
    return c;
}

int mergeSort(int arr[],int l,int h){
    int c = 0;
    if(l<h){
        int mid = l + (h-l)/2;
        c += mergeSort(arr,l,mid);
        c += mergeSort(arr,mid+1,h);

        c += merging(arr,l,mid,h);
    }
    return c;
}

int MinSwapCountUtil(int arr[],int n){
    return mergeSort(arr,0,n-1);
}

int main(void){

    int arr [] = {8,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<MinSwapCountUtil(arr,n); //o/p: 6
    return 0;
}

