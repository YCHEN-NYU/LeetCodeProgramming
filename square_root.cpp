/*
迭代法求方程根
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// use recursive method to find the square root of a number
// x[n + 1] = 1/2*(x[n] + a/x[n]);
#define Epsilon  1.0e-6

double __sqrt__(double number){
	double x_prev = 1.0;
	double x_next = 0.5*(x_prev + number/x_prev);
	while(abs(x_prev - x_next) > Epsilon){
		x_prev = x_next;
		x_next = 0.5*(x_prev + number/x_prev);
	}
	return x_next;

}

int main() {
	cout.precision(7);
	cout << __sqrt__(2.0) << endl;

	return 0;
}
