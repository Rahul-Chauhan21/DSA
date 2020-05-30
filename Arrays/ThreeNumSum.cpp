/*
    Given a non-empty array of distinct integers and an integer representing a target sum. write a function
    to find all the triplets in the array that sum up to the target sum and return a two-dimensional array
    of these triplets, triplets themselves should be ordered in ascending order with respect to the
    numbers they hold.

    if no three numbers sum up to the target sum, function should return an empty array
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n^2) time | O(n) space
vector<vector<int>> threeNumSum(vector<int> array, int targetSum){
    vector<vector<int>> res;
    sort(array.begin(),array.end());
        for(int i = 0; i < array.size() - 2; i++){
            int left = i + 1, right = array.size() - 1;
            while(left < right){
                int currSum = array[i] + array[left] + array[right];

                if(currSum == targetSum){
                    res.push_back({array[i],array[left],array[right]});
                    left++;
                    right--;
                }
                else if(currSum < targetSum){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    return res;
}

int main(void){
    vector<int> array = {12,3,1,2,-6,5,-8,6};
    int targetSum = 0;
    vector<vector<int>> res = threeNumSum(array,targetSum);
    if(res.empty()){
        cout<<"No such triplet";
    }
    else{
        /*
         o/p:
         [-8,2,6]
         [-8,3,5]
         [-6,1,5]
        */
        for(auto i = 0; i < res.size(); i++){
            for(int j = 0; j < res[i].size(); j++){
                cout<< res[i][j] << " ";
            }
            cout<<endl;
        }
    }
}
