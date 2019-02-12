#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
void print_vector(vector<T> & vect){
    for(int i = 0; i < vect.size(); i++){
        cout << vect.at(i) << '\t';
    }   cout << endl;
}

template <typename T>
void print_vector_rev(vector<T> & vect){
    for(vector<T>::reverse_iterator  it = vect.rbegin(); it != vect.rend(); ++it){
        cout << *it << '\t';
    }   cout << endl;
}

int main() {
    vector<string> strs;
    strs.push_back("apple");
    strs.push_back("orange");
    strs.push_back("banana");

    print_vector(strs);

    strs.insert(strs.begin() + 3, 2, "pear");

    print_vector(strs);

    strs.erase(strs.begin() + 1, strs.begin() + 3);

    print_vector(strs);

    print_vector_rev(strs);


    return 0;
}