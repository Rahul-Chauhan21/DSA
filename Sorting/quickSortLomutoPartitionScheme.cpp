#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void swap_func(int *a, int *b){
    if(*a==*b)
        return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    /*int t = *a;
    *a = *b;
    *b = t;*/
}
//using lomuto partition scheme
int partition_logic(int arr[],int low,int high){
    int pivot = arr[high];

    int p_index = low-1;

        for(int j= low; j<high; j++){
            if(arr[j]<=pivot){
                p_index++;
                swap_func(&arr[j],&arr[p_index]);
            }
        }
            swap_func(&arr[high],&arr[p_index+1]);
    return p_index+1;
}
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(0));
    int random = low + rand() % (high - low);
    // Swap A[random] with A[high]
    swap_func(&arr[random],&arr[high]);
    return partition_logic(arr, low, high);
}
// O(N*logN) time | O(N) space recursion call stack. Best and Average Case
// O(N^2) time | O(N) space recursion call stack. Worst case
/*void quicksort(int arr[],int low,int high){
    //O(N) calls to function stack.
    if(low<high){
        int pi = partition_r(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}*/
// O(N*logN) time | O(logN) space recursion call stack. Best and Average Case
// O(N^2) time | O(logN) space recursion call stack. Worst case
void quicksort(int arr[], int low, int high){
    if(low < high){
        int pivot_index = partition_r(arr,low,high);
        bool leftSubarrayIsSmaller = pivot_index - 1 - low < high - (pivot_index + 1);
        //(logN) calls handled with tail recursion
        if(leftSubarrayIsSmaller){
            quicksort(arr,low,pivot_index - 1);
            quicksort(arr,pivot_index + 1, high);
        }
        else{
            quicksort(arr,pivot_index + 1, high);
            quicksort(arr,low,pivot_index - 1);
        }
    }
}
int main(void){
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
        quicksort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}
