//
// Created by eason on 6/17/2018.
//

#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List() {
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}

void List::AddNode(int addData) {
    nodePtr n = new node;
    n->next = nullptr;
    n->data = addData;

    if(head != nullptr){
        curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = n;
    }
    else {
        head = n;
    }
}

void List::DeleteNode(int delData){
    nodePtr delPtr = nullptr;
    temp = head;
    curr = head;
    while((curr != nullptr) && (curr->data != delData)){
        temp = curr;
        curr = curr->next;
    }
    if(curr == nullptr){
        cout << delData << " was not in the list" << endl;
        delete delPtr;
    }
    else {
        delPtr = curr;
        if(delPtr == head){
            head = head->next;
            temp = nullptr;
        }
        
        curr = curr->next;
        temp->next = curr;
        delete delPtr;
        cout << "This value " << delData << " was deleted" << endl;
    }
}

void List::PrintList() {
    curr = head;
    while(curr != nullptr){
        cout <<  curr->data << endl;
        curr = curr->next;
    }


}

