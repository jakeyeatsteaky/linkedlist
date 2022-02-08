//
//  LinkedList.hpp
//  LinkedList Template
//
//  Created by Jake on 2/7/22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    
};

class LinkedList
{
public:
    LinkedList();
    Node *createNode(int value);
    void printList();
    void push_front(int value);
    void insertNodeAtPosition(int pos, int value);
    int pop_front();
    int pop_back();
    int removeByIndex(int idx);
    int removeByValue(int valueToDelete);
    void removeDuplicatesFromLinkedList();
protected:
    Node *head;
    Node *tail;
    
};

#endif /* LinkedList_hpp */
