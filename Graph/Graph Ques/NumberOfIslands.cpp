#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols){
    if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != '1')
        return;
    grid[i][j] = '2';
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
    dfs(grid, i ,j + 1, rows, cols);
}
// O(N * M ) time
int numIslands(vector<vector<char>>& grid){
    int rows = grid.size();
    if(rows == 0){
        return 0;
    }
    int cols = grid[0].size();
    int numOfIslands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,rows,cols);
                    numOfIslands += 1;
                }
            }
        }
    return numOfIslands;
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'0'));
        for(auto i = 0; i < grid.size(); i++){
                for(auto j = 0; j < grid[0].size(); j++){
                    cin>> grid[i][j];
                }
            }
    cout<< numIslands(grid);
    return 0;
}
