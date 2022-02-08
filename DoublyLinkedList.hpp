//
//  DoublyLinkedList.hpp
//  LinkedList Template
//
//  Created by Jake on 2/7/22.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include "LinkedList.hpp"

class DoublyLinkedList : public LinkedList
{
public:
    void insertBefore(Node *node, Node *nodeToInsert);
    void insertAfter(Node *node, Node *nodeToInsert);
    void setHead(Node *node);
    void setTail(Node *node);
    void insertAtPosition(int position, Node *nodeToInsert);
    void removeNodesWithValue(int value);
    void remove(Node *node);
    void removeNodeBindings(Node *node);
    bool containsNodeWithValue(int value);
};
#endif /* DoublyLinkedList_hpp */
