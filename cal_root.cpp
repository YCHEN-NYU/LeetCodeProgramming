/*
用牛顿迭代法 求方程 2*x*x*x-4*x*x+3*x-6 的根
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#define epsilon 1.0e-6
using namespace std;

// x[n + 1] = x[n] - f(x[n])/f'(x[n])

double f(double x, double p3 = -1.0, double p2 = -4, 
				 double p1 = 3.0, double p0 = -6.0){
	return p3*x*x*x + p2*x*x + p1*x + p0;
}

double df(double x, double p3 = -1.0, 
					double p2 = -4, double p1 = 3.0){
	return 3*p3*x*x + 2*p2*x + p1;
}

double __root__(double number){
	double x_prev = number;
	double x_next = x_prev - f(x_prev)/df(x_prev);

	while(abs(x_next - x_prev) > epsilon){
		x_prev = x_next;
		x_next = x_prev - f(x_prev)/df(x_prev);
	}
	return x_next;

}


int main() {
	cin.precision(6);
	cout << __root__(1.482) << endl;
	cout << __root__(-1.0) << endl;
	cout << __root__(0.0) << endl;
}