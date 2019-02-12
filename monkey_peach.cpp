/*
题目：一只猴子摘了 N 个桃子第一天吃了一半又多吃了一个,第二天又吃了余下的
一半又多吃了一个,到第十天的时候发现还有一个.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int num_peach(int number_of_days){
	int number_of_peaches = 1;
	for(int i = number_of_days; i > 1; i--){
		number_of_peaches = (number_of_peaches + 1)*2;
	}
	return number_of_peaches;
}


int main() {
	
	cout << "第一天共摘了" << num_peach(10) << "个桃" << endl;

}



