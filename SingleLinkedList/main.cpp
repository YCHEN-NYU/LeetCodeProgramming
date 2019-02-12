#include <iostream>
#include <cstdlib>
#include "List.h"
using namespace std;

int main() {
    List Eason;

    Eason.AddNode(100);
    Eason.AddNode(200);
    Eason.AddNode(300);
    Eason.PrintList();

    Eason.DeleteNode(200);
    Eason.PrintList();

    Eason.DeleteNode(300);
    Eason.PrintList();

    Eason.DeleteNode(100);
    Eason.PrintList();

    return 0;
}