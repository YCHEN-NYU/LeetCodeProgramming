/*
 127. Word Ladder
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 
 Only one letter can be changed at a time.
 Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 Note:
 
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 You may assume no duplicates in the word list.
 You may assume beginWord and endWord are non-empty and are not the same.
 Example 1:
 
 Input:
 beginWord = "hit",
 endWord = "cog",
 wordList = ["hot","dot","dog","lot","log","cog"]
 
 Output: 5
 
 Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 Example 2:
 
 Input:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 
 Output: 0
 
 Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include "printMatrix1D.h"
using namespace std;

void addWords(unordered_set<string> &dict, queue<string> &Q, string word){
    // replace one character in word, see if the new word == endWord
    for(int i = 0; i < word.size(); i++){
        char c = word[i]; // store character that's gonna be replaced
        for(int j = 0; j < 26; j++){
            word[i] = 'a' + j;
            // if word in dict, then put it to Q
            if(dict.find(word) != dict.end()){
                Q.push(word);
                dict.erase(word);
            }
        }
        word[i] = c;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> Q;
    Q.push(beginWord);
    int ladder = 1;
    while(!Q.empty()){
        int len = Q.size();
        
        for(int i = 0; i < len; i++){
            string word = Q.front();
            Q.pop();
            if(word == endWord){
                return ladder;
            }
            // check if one character is replaced in word can get word == endWord
            addWords(dict, Q, word);
        }
        ladder++;
    }
    return 0;
}


int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << "ladder length = " << ladderLength(beginWord, endWord, wordList) << endl;
}
