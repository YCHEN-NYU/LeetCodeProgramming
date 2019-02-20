/*
 64. Minimum Path Sum
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time.
 
 Example:
 Input:
 [
 [1,3,1],
 [1,5,1],
 [4,2,1]
 ]
 Output: 7
 Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
#include <iostream>
#include <vector>
using namespace std;


int minPathSum(vector<vector<int>>& grid) {
    int ROWS = grid.size(), COLUMNS = grid[0].size();
    if(ROWS == 0 || COLUMNS == 0)   return 0;
    
    vector<vector<int>> sum(ROWS, vector<int>(COLUMNS, 0));
    // last row
    for(int col = COLUMNS - 1; col >= 0; col--){
        if(col == COLUMNS - 1)  sum[ROWS - 1][col] = grid[ROWS - 1][col];
        else    sum[ROWS - 1][col] += grid[ROWS - 1][col] + sum[ROWS - 1][col + 1];
    }
    
    // last column
    for(int row = ROWS - 1; row >= 0; row--){
        if(row == ROWS - 1)
            sum[row][COLUMNS - 1] = grid[row][COLUMNS - 1];
        else
            sum[row][COLUMNS - 1] += sum[row + 1][COLUMNS - 1] + grid[row][COLUMNS - 1];
    }
    
    // right to left, bottom to top
    for(int row = ROWS - 2; row >= 0; row--){
        for(int col = COLUMNS - 2; col >= 0; col--){
            sum[row][col] += min(sum[row + 1][col], sum[row][col + 1]) + grid[row][col];
        }
    }
    return sum[0][0];
}


int main(){
    vector<vector<int>> grid= {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "sum(min path) = " << minPathSum(grid) << endl;
}
