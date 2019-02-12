/*
题目：将一个数组逆序输出。
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	vector<int> number_list = {-5, -1, 0, 2, 3, 5, 8};
	
	for(int i = number_list.size() - 1; i >= 0; i--)
		cout << setw(4) << number_list[i];
	cout << endl; 

}
