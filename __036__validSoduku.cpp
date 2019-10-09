/*
 6. Valid Sudoku
 Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 
 Each row must contain the digits 1-9 without repetition.
 Each column must contain the digits 1-9 without repetition.
 Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

 The Sudoku board could be partially filled, where empty cells are filled with the character '.'

 Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> validCharSet = {'.', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    return checkRows(board, validCharSet)
    && checkColumns(board, validCharSet)
    && check3by3Grids(board, validCharSet);
}

bool checkRows(vector<vector<char>> &board, unordered_set<char> &validCharSet){
    int ROWS = board.size(), COLUMNS = board[0].size();
    // 1-9, use hashtable SET to chekc non-repetition
    for(int row = 0; row < ROWS; row++){
        unordered_set<char> charSet; // reset
        for(int col = 0; col < COLUMNS; col++){
            if(validCharSet.find(board[row][col]) == validCharSet.end())
                return false;
            else{
                if(charSet.find(board[row][col]) != charSet.end()
                   && board[row][col] != '.')
                    return false;
                else
                    charSet.insert(board[row][col]);
            }
        }
    }
    return true;
}

bool checkColumns(vector<vector<char>> &board, unordered_set<char> &validCharSet){
    int ROWS = board.size(), COLUMNS = board[0].size();
    for(int col = 0; col < COLUMNS; col++){
        unordered_set<char> charSet; // reset
        for(int row = 0; row < ROWS; row++){
            if(validCharSet.find(board[row][col]) == validCharSet.end())
                return false;
            else{
                if(charSet.find(board[row][col]) != charSet.end()
                   && board[row][col] != '.')
                    return false;
                else{
                    charSet.insert(board[row][col]);
                }
            }
        }
    }
    return true;
}

bool check3by3Grids(vector<vector<char>> &board, unordered_set<char> &validCharSet){
    int ROWS = board.size(), COLUMNS = board[0].size();
    for(int gridRow = 0; gridRow < ROWS/3; gridRow++){
        for(int gridCol = 0; gridCol < COLUMNS/3; gridCol++){
            unordered_set<char> charSet; // reset
            for(int row = 0; row < 3; row++){
                for(int col = 0; col < 3; col++){
                    int rowIndex = row + gridRow*3, colIndex = col + gridCol*3;
                    if(validCharSet.find(board[rowIndex][rowIndex]) == validCharSet.end())
                        return false;
                    else{
                        if(charSet.find(board[rowIndex][colIndex]) != charSet.end()
                           && board[rowIndex][colIndex] != '.')
                            return false;
                        else
                            charSet.insert(board[rowIndex][colIndex]);
                    }
                }
            }
            
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board = {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    }
}
