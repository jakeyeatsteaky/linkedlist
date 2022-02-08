#include <iostream>
#include <vector>
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"


int main() {
    Node *node2 = new Node;
    node2->data = 45; node2->next = nullptr; node2->prev = nullptr;
    Node *newNode = new Node;
    newNode->data = 55; newNode->next = nullptr; newNode->prev = nullptr;
    Node *node3 = new Node;
    node3->data = 65; node3->next = nullptr; node3->prev = nullptr;
    Node *node4 = new Node;
    node4->data = 50; node4->next = nullptr; node4->prev = nullptr;
    Node *node5 = new Node;
    node5->data = 47; node5->next = nullptr; node5->prev = nullptr;
    Node *node6 = new Node;
    node6->data = 52; node6->next = nullptr; node6->prev = nullptr;
    Node *node7 = new Node;
    node7->data = 70; node7->next = nullptr; node7->prev = nullptr;
    Node *node8 = new Node;
    node8->data = 5; node8->next = nullptr; node8->prev = nullptr;
    Node *node9 = new Node;
    node9->data = 3; node9->next = nullptr; node9->prev = nullptr;
    Node *node10 = new Node;
    node10->data = 40; node10->next = nullptr; node10->prev = nullptr;
    Node *node11 = new Node;
    node11->data = 1; node11->next = nullptr; node11->prev = nullptr;
    Node *node12 = new Node;
    node12->data = 2; node12->next = nullptr; node12->prev = nullptr;
    
    LinkedList SampleList;
    SampleList.createNode(5);
    SampleList.createNode(10);
    SampleList.createNode(15);
    SampleList.printList();
    std::cout << "----------------------------------\n";
}


