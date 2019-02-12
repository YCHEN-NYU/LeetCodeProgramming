/*
利用while语句,条件为输入的字符不为'\n'.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> arr;
	char c;
	int n = 0;
	while((c = getchar()) != '\n' && (n < 100)){
		arr.push_back(c);
		n++;
	}
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << endl;
	}

	return 0;
}