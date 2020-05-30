/*
 Write a function that takes two non empty arrays of integers, find the pair of numbers whose absolute diff
 is closest to zero and return an array containing two such numbers, with the number from the first
 array in the first position.

 Assumption: only one such pair forms the smallest difference
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//O(nlog(n) + mlog(m)) time | O(1) space
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo){
    vector<int> res;
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int i = 0, j = 0;
    int smallestDiff = INT_MAX;
    int currDiff = INT_MAX;
        while(i < arrayOne.size() && j < arrayTwo.size()){
            int firstNum = arrayOne[i];
            int secNum = arrayTwo[j];

            currDiff = abs(firstNum - secNum);
            if(currDiff == 0){
                return vector<int>{firstNum,secNum};
            }
            else if(firstNum > secNum){
                j++;
            }
            else{
                i++;
            }

            if(smallestDiff > currDiff){
                smallestDiff = currDiff;
                res = {firstNum, secNum};
            }
        }
    return res;
}

int main(void){
    vector<int> arrayOne = {-1,5,10,20,28,3};
    vector<int> arrayTwo = {26,134,135,15,17};

    vector<int> res = smallestDifference(arrayOne,arrayTwo);
        for(auto i = 0; i < res.size(); i++){
            cout<< res[i] << " ";
        }
    return 0;
}
