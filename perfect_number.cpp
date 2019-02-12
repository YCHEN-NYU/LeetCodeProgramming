/*
题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如 6=1＋2
＋3.编程找出 1000 以内的所有完数。
*/


#include <iostream>
#include <iomanip>

using namespace std;


bool isPerfectNumber(int num){
	int sum = 0;

	for(int i = 1; i < num; i++)
		if(num % i == 0)	sum += i;

	return sum == num;
}

int main(){

	for(int i = 1; i < 1000; i++){
		if(isPerfectNumber(i))
			cout << i << endl;
	}

}