#include <iostream>
#include <string>
#include <cstdlib>
#include "hash.h"
using namespace std;

int main() {
    hasho hashOjbect;
    int index = hashOjbect.Hash("Easona");
    cout << "index = " << index << endl;
    return 0;
}