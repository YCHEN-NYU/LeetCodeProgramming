/*
 130. Surrounded Regions
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 Example:
 X X X X
 X O O X
 X X O X
 X O X X
 
 After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X
 Explanation:
 
 Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
#include <iostream>
#include <vector>
#include "printMatrix2D.h"
using namespace std;

void check(vector<vector<char>> &board, int row, int col, int ROWS, int COLUMNS){
    if(board[row][col] == 'O'){
        board[row][col] = '1';
        if(row > 1) check(board, row - 1, col, ROWS, COLUMNS); // top
        if(col > 1) check(board, row, col - 1, ROWS, COLUMNS); // left
        if(row < ROWS - 1)  check(board, row + 1, col, ROWS, COLUMNS); // bottom
        if(col < COLUMNS - 1)   check(board, row, col + 1, ROWS, COLUMNS); // right
    }
}

void solve(vector<vector<char>>& board) {
    int ROWS = board.size();
    if(ROWS == 0)   return;
    int COLUMNS = board[0].size();
    
    // check if first and last row has 'O', traverse neighbors using resursive method in check()
    for(int col = 0; col < COLUMNS; col++){
        check(board, 0, col, ROWS, COLUMNS);
        if(ROWS > 1){
            check(board, ROWS - 1, col, ROWS, COLUMNS);
        }
    }
    
    // check if first and last col has 'O', traverse neighbors using resursive method in check()
    for(int row = 1; row < ROWS - 1; row++){
        check(board, row, 0, ROWS, COLUMNS);
        if(COLUMNS > 1){
            check(board, row, COLUMNS - 1, ROWS, COLUMNS);
        }
    }
    
    // flip 'O' to 'X'
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            if(board[row][col] == 'O')
                board[row][col] = 'X';
        }
    }
    
    // flip '1' to 'O'
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            if(board[row][col] == '1')
                board[row][col] = 'O';
        }
    }
}


int main(){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    cout << "original matrix = " << endl;
    printMatrix2D(board);
    solve(board);
    cout << "flipped matrix = " << endl;
    printMatrix2D(board);
}
