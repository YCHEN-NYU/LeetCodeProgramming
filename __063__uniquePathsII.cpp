/*
 63. Unique Paths II
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
  Note: m and n will be at most 100.
 
 Example 1:
 Input:
 [
 [0,0,0],
 [0,1,0],
 [0,0,0]
 ]
 
 Output: 2
 
 Explanation:
 There is one obstacle in the middle of the 3x3 grid above.
 There are two ways to reach the bottom-right corner:
 1. Right -> Right -> Down -> Down
 2. Down -> Down -> Right -> Right
 */

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsII(vector<vector<bool>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if(m == 0 || n == 0)    return 0;
    
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    matrix[m - 1][n - 1] = 1;
    for(int row = m - 1; row >= 0; row--){
        for(int col = n - 1; col >= 0; col--){
            matrix[row][col] += (row + 1 < m && obstacleGrid[row + 1][col] == 0? matrix[row + 1][col] : 0);
            matrix[row][col] += (col + 1 < n && obstacleGrid[row][col + 1] == 0? matrix[row][col + 1] : 0);
        }
    }
    return matrix[0][0];
}

int main(){
//    vector<vector<int>>  numList = {{1, 0}, {2, 3}, {2, 4}, {3, 4}, {7, 3}};
//    for (auto num : numList) {
//        cout << "(" << num[0] << ", " << num[1] << "): ";
//        cout << uniquePaths(num[0], num[1]);
//        cout << endl;
//    }
    vector<vector<bool>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "# of path = " << uniquePathsII(obstacleGrid) << endl;
}

