/*
 79. Word Search
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 Example:
 board =
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 
 Given word = "ABCCED", return true.
 Given word = "SEE", return true.
 Given word = "ABCB", return false.
 */
#include <iostream>
#include <vector>
#include "printMatrix2D.h"
using namespace std;

bool helper(vector<vector<char>> &board, string word, int start, int row, int col, vector<vector<bool>> &used){
    
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[start] || used[row][col])
        return false;
    
    if(start == word.size() - 1) return true;
    
    
    used[row][col] = true;
    if(helper(board, word, start + 1, row - 1, col, used) ||
       helper(board, word, start + 1, row, col - 1, used) ||
       helper(board, word, start + 1, row, col + 1, used) ||
       helper(board, word, start + 1, row + 1, col, used))
        return true;
    
    used[row][col] = false; // reset the used[row][col] to false
    return false;
    
}

bool exist(vector<vector<char>>& board, string word) {
    int ROWS = board.size(), COLUMNS = board[0].size();
    vector<vector<bool>> used(ROWS, vector<bool>(COLUMNS, false));
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            if(helper(board, word, 0, row, col, used))
                return true;
            else
                continue;
        }
    }
    return false;
}



int main(){
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    vector<string> words = {"ABCCED", "SEE", "ABCB"};
    cout << "board: " << endl;
    printMatrix2D(board);
    cout << endl;
    for (auto word:words) {
        if (exist(board, word)) {
            cout << word << " exists in the board." << endl;
        }
        else{
            cout << word << " NOT exists in the board." << endl;
        }
    }
    return 0;
}
