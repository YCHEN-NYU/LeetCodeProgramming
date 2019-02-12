#include <iostream>
using namespace std;

//int increment(int & number){
//    return ++number;
//}

int increment(int * ptr){
    return ++(*ptr);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr;
    ptr = arr;
    cout << *ptr << endl;
    ptr++;
    cout << *ptr << endl;
    ptr = arr + 2;
    cout << *ptr << endl;

    int * number = new int;
    *number = 1;
    cout << &number <<endl;
    cout << *number <<endl;
    delete &number;
    return 0;
}