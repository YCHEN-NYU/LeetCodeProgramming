// Use of pair
#include <utility>
#include <iostream>
#include <string>
using namespace std;

int main(){
	std::pair<int, int> mypair(INT_MIN, INT_MAX);
	std::pair<int, int> youpair(mypair);
	cout << "mypair: <";
	cout << mypair.first;
	cout << ", ";
	cout << mypair.second;
	cout << ">" << endl;
	cout << "youpair: <";
	cout << youpair.first;
	cout << ", ";
	cout << youpair.second;
	cout << ">" << endl;
}