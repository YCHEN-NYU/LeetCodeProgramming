//
// Created by eason on 6/17/2018.
//

#ifndef HASH_BABLE1_HASH_H
#define HASH_BABLE1_HASH_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class hasho {
private:
    static const int table_size = 10;

    struct item {
        string name;
        string drink;
        item * next;
    };

    item * HashTable[table_size];

public:
    hasho();
    int Hash(string key);

};


#endif //HASH_BABLE1_HASH_H
