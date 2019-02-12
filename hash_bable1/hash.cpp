//
// Created by eason on 6/17/2018.
//

#include "hash.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

hasho::hasho(){
    for(int i = 0; i < table_size; i++){
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
}
int hasho::Hash(string key) {
    int hash = 0, index;
    index = key.length();

    for(int i = 0; i < key.size(); i++){
       hash += int(key[i]);
       cout << "hash = " << hash << endl;
    }

    index = hash % table_size;
    return index;
}

