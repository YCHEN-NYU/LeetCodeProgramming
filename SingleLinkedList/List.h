//
// Created by eason on 6/17/2018.
//

#ifndef SINGLELINKEDLIST_LIST_H
#define SINGLELINKEDLIST_LIST_H


class List {
private:

    typedef struct node {
        int data;
        node * next;
    } * nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
};


#endif //SINGLELINKEDLIST_LIST_H
