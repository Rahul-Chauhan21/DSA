// given two non-empty array of integers, write a function that determines whether the second array
// is a subsequence of the first one.

#include <iostream>
#include <vector>
using namespace std;
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int arrIdx = 0, seqIdx = 0;
		while(arrIdx < array.size() && seqIdx < sequence.size()){
			if(array[arrIdx] == sequence[seqIdx]){
				seqIdx++;
			}
			arrIdx++;
		}
	return seqIdx == sequence.size();
}

int main(void){
    vector<int> array = {5,1,22,25,6,-1,8,10};
    vector<int> sequence = {1,6,-1,10};
    // test case o/p: 1
    cout<< isValidSubsequence(array,sequence);
}
