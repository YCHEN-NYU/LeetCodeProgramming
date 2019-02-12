/*
题目：打印出如下图案（菱形）
*/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	int N = 11;
	for(int i = 0; i < N; i++){
		if(i <= N/2 ){
			cout << string(2*i + 1, '*') << endl;
		}
		else{
			cout << string(N - 2*(i - N/2), '*') << endl;
		}
	}



}