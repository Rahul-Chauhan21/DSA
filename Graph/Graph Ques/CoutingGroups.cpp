/*
Problem Statement:
Consider a 2D array, n x n matrix where each cell contains either the value 0 or 1. Any two cells
in the matrix fall into the same group if |x[1] - x[2]| + |y[1] -y[2]| = 1(they adjoin by row or column)
and both cells contains the value 1. Determine the sizes of all the groups in the matrix, then for each test
in query array, append the number of groups of that size to return array.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int count;

/*
Test Cases:
I/P:
6 6
1 1 1 1 1 1
1 1 0 0 0 0
0 0 0 1 1 1
0 0 0 1 1 1
0 0 1 0 0 0
1 0 0 0 0 0
4
1 2 6 8
O/P: 2 0 1 1

10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 1 1 1
1 1 0 0 1 0 0 1 1 1
1 0 1 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
5
1 10 20 2 6

o/p: 2 2 1 1 1

5 5
1 0 1 1 0
0 1 0 0 1
1 0 1 1 0
1 0 1 1 0
0 1 0 0 1
5
1 2 3 4 5
o/p: 5 2 0 1 0
*/


void dfs(vector<vector<int>> &grid, int i, int j){
    if(i < 0 || j < 0 || i>= grid.size()|| j>= grid[0].size() || grid[i][j] != 1){
        return;
    }
    count++;
    grid[i][j] = 2;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}
// O(n * n) time | O(len(queries))
vector<int> countGroups(vector<vector<int>>& grid, vector<int>& queries){
    unordered_map<int,int> sizes;
    vector<int> res(queries.size(), 0);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count = 0;
                    dfs(grid,i,j);

                    if(sizes.find(count) == sizes.end()){
                        sizes.insert({count,1});
                    }
                    else{
                        sizes[count]++;
                    }
                }
            }
        }

        for(int i = 0; i < queries.size();i++){
            if(sizes.find(queries[i]) != sizes.end()){
                res[i] = sizes[queries[i]];
            }
        }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
        for(auto i = 0; i < grid.size(); i++){
            for(auto j = 0; j < grid[0].size(); j++){
                cin>>grid[i][j];
            }
        }
    int q;
    cin>>q;
    vector<int> queries;
        for(int i = 0; i < q; i++){
            int val;
            cin>>val;
            queries.push_back(val);
        }
    vector<int> res = countGroups(grid,queries);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
 return 0;
}
