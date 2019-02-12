#include <iostream>
using namespace std;

#define PI 3.141593

double circle_area(double radius){
    return PI*radius*radius;
}


int main(){
    
    cout << "area = " << circle_area(3.0) << endl;
}

