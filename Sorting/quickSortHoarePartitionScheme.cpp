/*
Hoare's Partition Scheme
By picking a pivot, every number that is smaller than the pivot is to be moved to the left of the pivot
By doing this the pivot is fixed at the correct index

we keep reapplying this tech to the subarray to the left with respect to the newly placed pivot and onto the
subarray to the right of the pivot, we do that until the entire array is sorted.
*/

/*
whenever the left pointer was pointing to a number greater than our pivot and whenever the right pointer was pointed
at number smaller than the pivot then we swapped left and right numbers. we were effictively putting the greater left number
to the right of the final positon of the pivot and effectively placing the smaller right number to the left of the final
position of the pivot and we kept incrementing and decrementing our left and right pointers until they paassed each other
*/
/*
For the Worst Case:
	if the pivot divides our array into one tiny list of length like one and the one huge list or one huge subarray of length'
	n-1 or n-2 where n is the length of subarray and if that keeps happening everytime we apply quicksort on the subarray
	we effectively run in n^2 time
	eg. a sorted listed ascending or descending.
For the Best Case:
	if the pivot divides the array in half we are making log(n) calls of quicksort until we reach sub arrays of length 1.
	every call of quicksort roughly takes O(n) time because of the left and right pointers that are iterating through the
	subarray which tends to be O(n). we have a time complexity of O(nlogn)
*/
/*
Space Complexity Analysis:
	Applying quicksort on the smallest of the two subarrays first, then we make atmost O(log N) calls.
	In the worst case:
		We use concept of tail recursion that removes the memory usage in the call stack in a lot of languages
*/
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

void quickSortHelper(vector<int> &array, int startIdx, int endIdx);
vector<int> quickSort(vector<int> &array) {
	quickSortHelper(array, 0, array.size() - 1);
	return array;
}
//using Hoare's partition scheme
int partition_logic(vector<int> &arr, int startIdx, int endIdx){
	int pivotIdx = startIdx;
	int leftIdx = startIdx + 1;
	int rightIdx = endIdx;
	while(leftIdx <= rightIdx){
		if(arr[leftIdx] > arr[pivotIdx] && arr[rightIdx] < arr[pivotIdx]){
			swap(arr[leftIdx],arr[rightIdx]);
		}
		if(arr[leftIdx] <= arr[pivotIdx]){
			leftIdx += 1;
		}
		if(arr[rightIdx] >= arr[pivotIdx]){
			rightIdx -= 1;
		}
	}
	swap(arr[rightIdx],arr[pivotIdx]);
	return rightIdx; // right index ensures correct pos for pivot element.
}
int partition_random(vector<int> &arr, int startIdx, int endIdx){
	srand(time(0));
	int randomIdx = startIdx + rand() %(endIdx - startIdx);
	swap(arr[startIdx],arr[randomIdx]);
	return partition_logic(arr,startIdx,endIdx);
}

void quickSortHelper(vector<int> &arr, int startIdx, int endIdx){
	if(startIdx >= endIdx)
		return;
	int pivot_index = partition_random(arr,startIdx,endIdx);
	bool leftSubarrayIsSmaller = pivot_index - 1 - startIdx < endIdx - (pivot_index + 1);
	if(leftSubarrayIsSmaller){
		quickSortHelper(arr,startIdx,pivot_index - 1);
		quickSortHelper(arr,pivot_index + 1, endIdx);
	}
	else{
		quickSortHelper(arr,pivot_index + 1, endIdx);
		quickSortHelper(arr,startIdx,pivot_index - 1);
	}
}

int main(void){
    vector<int> arr = { 10, 7, 8, 9, 1, 5 };
        quickSort(arr);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}
