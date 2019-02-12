#include <iostream>
#include <vector>
using namespace std;

struct fruit {
    double weightPound;
    double priceDollar;
}apple, banana;


class ball{
    double x, y;
    double vx, vy;
    double ax, ay;
};

int main() {
    apple.priceDollar = 1.99;
    apple.weightPound = 2.0;
    banana.priceDollar = 0.5;
    banana.weightPound = 3.0;

    cout << "Total price of apple is " << apple.priceDollar*apple.weightPound << " $\n";
    cout << "Total price of banana is " << banana.priceDollar*banana.weightPound << " $\n";



    return 0;
}