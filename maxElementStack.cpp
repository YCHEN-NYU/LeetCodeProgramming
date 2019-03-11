#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i = 1;
    cin >> n;
    stack<pair<long, long>> elementStk, maxStk;
    while(i <= n){
        long query, element;
        pair<long, long> p1, p2;
        cin>>query;
        if(query == 1){
            // push
            cin >> element;
            elementStk.push(make_pair(query, element));
            if(maxStk.size() == 0){
                maxStk.push(make_pair(query, element));
            }
            else{
                p1 = maxStk.top();
                if(element > p1.second){
                    maxStk.push(make_pair(query, element));
                }
            }
        }
        else{
            if(query == 2){
                // pop
                p1 = elementStk.top();
                elementStk.pop();
                p2 = maxStk.top();
                if (p1.second == p2.second && p1.first == p2.first) {
                  maxStk.pop();
                }
            }
            else{
                // getMax
                p1 = maxStk.top();
                cout << p1.second << endl;
            }
        }
        i++;
    }   
    return 0;
}
