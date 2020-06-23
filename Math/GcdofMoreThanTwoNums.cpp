#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int findGcd(vector<int>& v){
    int result = v[0];
        for(int i = 0; i < v.size(); i++){
            result = gcd(v[i], result);

            if(result == 1){
                return 1;
            }
        }
    return result;
}

int main(void){
    vector<int> v = {2,4,6,8,16};
    cout<<findGcd(v);
    return 0;
}
