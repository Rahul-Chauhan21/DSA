/*
Given an array of non-negative integers, A, of length N, you are initially positioned at the first
index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

Input 1:
    A = [2, 1, 1]

Output 1:
    1

Explanation 1:
    The shortest way to reach index 2 is
        Index 0 -> Index 2
    that requires only 1 jump.

Input 2:
    A = [2,3,1,1,4]

Output 2:
    2

Explanation 2:
    The shortest way to reach index 4 is
        Index 0 -> Index 1 -> Index 4
    that requires 2 jumps.

*/
int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n <= 1)
        return 0;
    pair<int,int> interval = {0,0};
    int can_reach = -1;
    int jumps = 0;
        while(true){
            jumps++; /// [5,8] [9,15] within first interval if my can_reach is 15 i can check in the next interval
            // counting a jump in the previous interval
            for(int i = interval.first; i <= interval.second; i++){
                can_reach = max(can_reach,A[i]+i);
            }

            if(can_reach >= n -1){
                return jumps;
            }
            interval = {interval.second + 1, can_reach};
            if(interval.first > interval.second)
            return -1;
        }

}
