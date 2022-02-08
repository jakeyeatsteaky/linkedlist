//
//  LinkedList.cpp
//  LinkedList Template
//
//  Created by Jake on 2/7/22.
//
#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

Node *LinkedList::createNode(int value){ // same as push_back
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
    
    return newNode;
}

void LinkedList::printList(){
    Node *current = head;
    
    while(current != nullptr){
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void LinkedList::push_front(int value){
    Node *new_node;
    new_node = new Node;
    
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void LinkedList::insertNodeAtPosition(int pos, int value){
    Node *previous_node = new Node;
    Node *current_node = new Node;
    Node *new_node = new Node;
    current_node = head;
    
    for(int i = 1; i < pos; i++){
        previous_node = current_node;
        current_node = current_node->next;
    }
    new_node->data = value;
    previous_node->next = new_node;
    new_node->next = current_node;
}

int LinkedList::pop_front(){
    int retrievedValue = 0;
    Node *next_node = nullptr;
    
    next_node = head->next;      // new_node comes after the head
    retrievedValue = head->data; // assigning the data at the head to this int
    delete head;
    head = next_node; // the new head reference pointer = the Node * next_node
    
    return retrievedValue;
}

int LinkedList::pop_back(){
    int retrievedValue = 0;
    // if there is only one item in the list, remove it
    if(head->next == nullptr){
        retrievedValue = head->data;
        delete head;
        return retrievedValue;
    }
    // navigate to the second to the last node in the list
    Node *current_node = head;
    while(current_node->next->next != nullptr){
        current_node = current_node->next;
    }
    //now current_node points to the second to last item of the list, so lets remove current_node->next
    retrievedValue = current_node->next->data;
    delete current_node->next;
    current_node->next = nullptr;
    return retrievedValue;
}

int LinkedList::removeByIndex(int idx){
    int returnedValue = -1;
    Node *current_node = head;
    Node *node_to_delete = nullptr;
    
    if(idx == 0){
        return pop_front();
    }
    
    for(int i = 0; i < idx-1; i++){
        if(current_node->next == nullptr){
            return -1;
        }
        current_node = current_node->next;
    }
    
    node_to_delete = current_node->next;
    returnedValue = node_to_delete->data;
    current_node->next = node_to_delete->next;
    delete node_to_delete;
    
    return returnedValue;
}

int LinkedList::removeByValue(int valueToDelete){
    int returnedValue = -1;
    Node* current_node = head;
    Node* node_to_delete = nullptr;
    
    if(current_node->data == valueToDelete){
        node_to_delete = current_node;
        returnedValue = current_node->data;
        head = current_node->next; //reassign the head
        delete current_node;
        return returnedValue;}
    while(current_node->next != nullptr){
        if(current_node->next->data == valueToDelete){
            node_to_delete = current_node->next;
            returnedValue = node_to_delete->data;
            current_node->next = node_to_delete->next;
            delete node_to_delete;
            break;}
        current_node = current_node->next;
    }
    return returnedValue;
}

// algoExpert RemoveDuplicates from Linked List
void LinkedList::removeDuplicatesFromLinkedList(){
    LinkedList* SampleList = this;
    Node* node_to_delete;
    Node* current_node = this->head;
    
    while(current_node->next != nullptr){
        if(current_node->data == current_node->next->data){
            node_to_delete = current_node->next;
            current_node->next = node_to_delete->next;
            delete node_to_delete;
        }
        else if(current_node->data == current_node->next->data){
                SampleList->removeDuplicatesFromLinkedList();

        }
        else current_node = current_node->next;
    }
}

