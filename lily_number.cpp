/*题目：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位
数字立方和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方
＋5的三次方＋3的三次方。
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

bool isLily(int num){
	int cubicSum = 0;
	// 153	370  371  407
	int digit_hundred = num/100;
	int digit_ten = (num - 100*digit_hundred)/10;
	int digit_one = num%10;

	cubicSum = pow(digit_one, 3) + pow(digit_ten, 3) + pow(digit_hundred, 3);

	return num == cubicSum;
}



int main() {
	vector<int> listLily;

	for(int i = 370; i < 372; i++){
		if(isLily(i))	listLily.push_back(i);
	}

	for(int i = 0; i < listLily.size(); i++){
		cout << setw(4) << listLily[i] << " ";
		if((i + 1)%10 == 0)	cout << endl;
	}	cout << endl;
}
