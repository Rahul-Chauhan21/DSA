/*
Write a function that takes in an array of integers and returns the length of the longest peak in the array

A peak is defined as adjacent integers in the array that are strictly increasing until they reach a tip,
at which point they become strictly decreasing. At least three integers are required to form a peak.
*/

//Sample input:
//[ 1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]

//Sample Output:
// 6 // 0, 10, 6, 5, -1, -3

#include <iostream>
#include <vector>
using namespace std;

int longestPeak(vector<int> array) {
  int longestPeakLength = 0;
	int i = 1;
		while(i < int(array.size() - 1)){
			bool isPeak = array[i - 1] < array[i] && array[i] > array[i + 1];
			if(!isPeak){
				i += 1;
				continue;
			}
			int leftIdx = i - 2;
			while(leftIdx >= 0 && array[leftIdx] < array[leftIdx + 1]){
				leftIdx -= 1;
			}

			int rightIdx = i + 2;
			while(rightIdx < array.size() && array[rightIdx] < array[rightIdx -1]){
				rightIdx += 1;
			}
			int currentPeakLength = rightIdx - leftIdx - 1;
			longestPeakLength = max(longestPeakLength, currentPeakLength);
			i = rightIdx;
		}
	return longestPeakLength;
}

int main(){
    int n;
    cin>>n;
    vector<int> input;
        for(int i = 0; i < n; i++){
            int val;
            cin>>val;
            input.push_back(val);
        }
    int longestPeakLength = longestPeak(input);
    cout<<longestPeakLength;
 return 0;
}
