#include <iostream>
#include <vector>
using namespace std;
//O(n) time | O(n) space
vector<int> spiralTraverse(vector<vector<int>> array) {
  if(array.size() == 0){
		return {};
	}
	vector<int> result = {};
	int startRow = 0, endRow = array.size() - 1, startCol = 0, endCol = array[0].size() - 1;
		while(startRow <= endRow && startCol <= endCol){
			for(int i = startCol; i <= endCol; i++){
				result.push_back(array[startRow][i]);
			}

			startRow++;

			for(int i = startRow; i <= endRow; i++){
				result.push_back(array[i][endCol]);
			}
			endCol--;

			if(startRow <= endRow){
				for(int i = endCol; i >= startCol; i--){
					result.push_back(array[endRow][i]);
				}
				endRow--;
			}

			if(startCol <= endCol){
				for(int i = endRow; i>= startRow; i--){
					result.push_back(array[i][startCol]);
				}
				startCol++;
			}
		}
	return result;
}

int main(void){
    vector<vector<int>> array = {{1,2,3,4},{10,11,12,5},{9,8,7,6}};
    vector<int> result = spiralTraverse(array);
        for(auto i = 0;i < result.size(); i++){
            cout<<result[i]<<" ";
        }
    return 0;
}
