/*
 题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数
 组中。
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int enter_integer() {
	int number;
	cout << "number = ";
	if(!(cin >> number)) enter_integer();
	return number;
}

int main() {
	vector<int> sorted_list = {-5, -1, 0, 3, 10, 20};
    int n = sorted_list.size();
	int number = enter_integer();
	for(int i = 0; i < sorted_list.size(); i++){
		if(number < sorted_list[i]){
			sorted_list.insert(sorted_list.begin() + i, number);
			break;
		}
	}
    if(sorted_list.size() == n)
        sorted_list.insert(sorted_list.begin() + n, number);
    
    for(int i = 0; i < sorted_list.size(); i++)
        cout << setw(5) << sorted_list[i];
    cout << endl;

	return 0;
	    
}
