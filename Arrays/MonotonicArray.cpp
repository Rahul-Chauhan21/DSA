#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(vector<int> array){
    bool isNonIncreasing = true, isNonDecreasing = true;
        for(int i = 0; i < array.size(); i++){
            if(array[i] < array[i - 1]){
                isNonDecreasing = false;
            }

            if(array[i] > array[i - 1]){
                isNonIncreasing = false;
            }
        }
    return isNonDecreasing || isNonIncreasing;
}

int main(){
    vector<int> input = {-1,-5,-10,-11,-11,-12,-111};
    bool res = isMonotonic(input);
    // test case o/p : 1
    cout<< res;
}
