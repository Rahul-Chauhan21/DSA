#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
//O(n log(n)) time | O(1) space
/*
vector<int> twoNumberSum(vector<int> array, int targetSum){
    sort(array.begin(),array.end());
    int left = 0;
    int right = array.size() - 1;
    while(left < right){
        int currSum = array[left] + array[right];
        if(currSum == targetSum){
            return {array[left],array[right]};
        }
        else if(currSum < targetSum){
            left++;
        }
        else{
            right--;
        }
    }
    return {};
}
*/

//O(n) time | O(n) space
vector<int>twoNumberSum(vector<int> array, int targetSum){
    unordered_set<int> st;
        for(int i = 0; i < array.size(); i++){
            int potentialMatch = targetSum - array[i];
                if(st.find(potentialMatch) != st.end()){
                    return {array[i], potentialMatch};
                }
                else{
                    st.insert(array[i]);
                }
        }
    return {};
}

int main(void){
    vector<int> array = {3,5,-4,8,11,-1,6};
    int targetSum = 10;
    vector<int> res = twoNumberSum(array,targetSum);
        for(auto i : res){
            cout<<i<<" ";
        }
    return 0;
}
