/*
 71. Simplify Path
 Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
 In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
 Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
 
 Example 1:
 
 Input: "/home/"
 Output: "/home"
 Explanation: Note that there is no trailing slash after the last directory name.
 Example 2:
 
 Input: "/../"
 Output: "/"
 Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

string simplifyPath(string path){
    string res = "", tmp;
    stringstream ss(path);
    stack<string> stk;
    while (getline(ss, tmp, '/')) {
        if(tmp == "" || tmp == ".") continue;
        if(tmp == ".." && !stk.empty()) stk.pop();
        else{
            if(tmp != "..") stk.push(tmp);
        }
    }
    
    while(!stk.empty()){
        res = "/" + stk.top() + res;
        stk.pop();
    }
    
    if(res.size() == 0)
        return "/";
    else
        return res;
    
}


int main(){
    vector<string> paths = {"/home/", "/../", "/home//foo/", "/a/./b/../../c/", "/a/../../b/../c//.//", "/a//b////c/d//././/.."};
    
    for (auto path : paths)
        cout << "\"" << path << "\"" << " --> " << "\"" << simplifyPath(path) << "\"" << endl;
    
    return 0;
}
