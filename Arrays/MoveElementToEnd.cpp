/*
    Given an array of integer and an integer. Write a function that moves all instances of that integer
    in the array to the end of the array and returns the array
*/
#include <iostream>
#include <vector>
using namespace std;

//O(n) time | O(1) space
vector<int> moveElementToEnd(vector<int> array, int toMove){
    int i = 0, j = array.size() - 1;
        while(i < j){
            while(i < j && array[j] == toMove){ // to ensure j doesn't cross i
                j--;
            }

            if(array[i] == toMove){
                swap(array[i],array[j]);
            }
            i++;
        }
    return array;
}

int main(void){
    vector<int> input = {2,1,2,2,2,3,4,2};
    int toMove = 2;
    vector<int> res = moveElementToEnd(input,toMove);
        // o/p : [4,1,3,2,2,2,2,2] 1,3,4 could be ordered differently
        for(auto i = 0; i < res.size(); i++){
            cout<< res[i] << " ";
        }
    return 0;
}
