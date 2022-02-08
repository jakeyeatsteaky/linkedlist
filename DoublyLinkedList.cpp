//
//  DoublyLinkedList.cpp
//  LinkedList Template
//
//  Created by Jake on 2/7/22.
//

#include "DoublyLinkedList.hpp"

void DoublyLinkedList::insertBefore(Node *node, Node *nodeToInsert) {
    Node *current_node = head;
    if(current_node == nullptr){
        this->head = nodeToInsert;
        this->tail = nodeToInsert;
        nodeToInsert->next = nullptr;
        nodeToInsert->prev = nullptr;
        return;
    }
    else if(current_node->next == nullptr || current_node == node ){
        this->head = nodeToInsert;
        current_node->prev = nodeToInsert;
        nodeToInsert->next = current_node;
        return;
    }
    else{
    while(current_node->next != node){
        current_node = current_node->next; //navigate to 1 before "node"
    }
    current_node->next = nodeToInsert;
    nodeToInsert->prev = current_node;
    node->prev = nodeToInsert;
    nodeToInsert->next = node;
}
}

void DoublyLinkedList::insertAfter(Node *node, Node *nodeToInsert) {
  
    Node *current_node = head;
    while(current_node != node){
        current_node = current_node->next;
    }
    if(current_node->next == nullptr){
        current_node->next = nodeToInsert;
        nodeToInsert->prev = current_node;
        nodeToInsert->next = nullptr;
        this->tail = nodeToInsert;
    } else if (node == this->head){
        this->insertBefore(this->head->next, nodeToInsert);
    } else{
    Node *nextToCurrent = current_node->next;
    current_node->next = nodeToInsert;
    nodeToInsert->prev = current_node;
    nodeToInsert->next = nextToCurrent;
    nextToCurrent->prev = nodeToInsert;
    }

}

void DoublyLinkedList::setHead(Node *node) {

    if(this->head == nullptr){
        this->head = node;
        this->tail = node;
        return;
    }
    insertBefore(this->head, node);
}

void DoublyLinkedList::setTail(Node *node) {
    if(this->tail == nullptr){
    this->head = node;
    this->tail = node;
    return;
    }
    insertAfter(this->tail, node);
}

void DoublyLinkedList::insertAtPosition(int position, Node *nodeToInsert) {
    Node *current_node = this->head;
    for(int i = 1; i < position; i++){
        current_node = current_node->next;
    }
    insertBefore(current_node, nodeToInsert);
}

void DoublyLinkedList::removeNodesWithValue(int value) {
    Node *node = head;
    while(node != nullptr){
        Node *nodeToRemove = node;
        node = node->next;
        if(nodeToRemove->data == value){
            remove(nodeToRemove);
        }
    }
}

void DoublyLinkedList::remove(Node *node){
    if(node == head){head = head->next;}
    if(node == tail){tail = tail->prev;}
    removeNodeBindings(node);
}

void DoublyLinkedList::removeNodeBindings(Node *node){
    if(node->prev != nullptr){node->prev->next = node->next;}
    if(node->next != nullptr){node->next->prev = node->prev;}
    node->prev = nullptr;
    node->next = nullptr;
}

bool DoublyLinkedList::containsNodeWithValue(int value) {
  
    Node *current_node = head;
    while(current_node != nullptr){
        if(current_node->data == value){return true;}
        current_node = current_node->next;
    }
  return false;
}
