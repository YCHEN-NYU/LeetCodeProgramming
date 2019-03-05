/*
 200. Number of Islands
 Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 
 Example 1:
 Input:
 11110
 11010
 11000
 00000
 
 Output: 1
 
 Example 2:
 Input:
 11000
 11000
 00100
 00011
 
 Output: 3
 */

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& grid, int row, int col, int rows, int columns){
    if(row >= 0 && row < rows && col >= 0 && col < columns && grid[row][col] == 1){
        grid[row][col] = 0; // mark it as '0' afterwards
        DFS(grid, row - 1, col, rows, columns);
        DFS(grid, row + 1, col, rows, columns);
        DFS(grid, row, col - 1, rows, columns);
        DFS(grid, row, col + 1, rows, columns);
    }
}

int numIslands(vector<vector<int>>& grid) {
    if(grid.size() == 0) return 0;
    int rows = grid.size(), columns = grid[0].size();
    int count = 0;
    
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < columns; col++){
            if(grid[row][col] == 1){
                DFS(grid, row, col, rows, columns);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> grid = {{1, 1, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0}};
    cout << "# of islands = " << numIslands(grid) << endl;
}
