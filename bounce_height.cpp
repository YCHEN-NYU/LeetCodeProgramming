/*
题目：一球从 100 米高度自由落下，每次落地后反跳回原高度的一半；再落下，
求它在第 10 次落地时，共经过多少米？第 10 次反弹多高？
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// n-th bounce height
double bounce_height(double h0, int n){
	return h0*pow(0.5, n);
}

// distance traveled at the n-th the ball hits the ground 
double total_distance_traveled(double h0, int n){
	if(n == 1)	return h0;
	return total_distance_traveled(h0, n - 1) + 2*bounce_height(h0, n - 1);
}



int main() {
	
	cout.precision(9);
	cout << "bounce_height(1, 2) = " 
			 << bounce_height(100, 10) << endl;
	cout << "total_distance_traveled(1, 2) = " 
			 << total_distance_traveled(100, 10) << endl;

}

// int main()
// {
// 	float sn=100.0,hn=sn/2;
// 	int n;
// 	for(n=2;n<=10;n++){
// 		sn=sn+2*hn;/*第n次落地时共经过的米数*/
// 		hn=hn/2; /*第n次反跳高度*/
// 	}
// 	printf("the total of road is %f\n",sn);
// 	printf("the tenth is %f meter\n",hn);
// }