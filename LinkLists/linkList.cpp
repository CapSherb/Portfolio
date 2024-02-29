//
// Created by richj on 5/23/2023.
//
#include "linkList.h"
#include <iostream>

using namespace std;

bool LinkList::isEmpty() {
    if(head == nullptr) {
        return true;
    } else {
        return false;
    }
}

void LinkList::insert_end(int num) { //Appending to the end of the list
    pNode = tail;
    if (isEmpty()) {
        Node* temp = new Node{num, nullptr, nullptr};
        head = temp;
        tail = temp;
        tail = temp;
    } else {
        Node* temp = new Node{num, nullptr, nullptr};
        pNode->next = temp;
        temp->prev = pNode;
        tail = temp;
    }
}

void LinkList::insert_front(int num) {
    if (isEmpty()) {
        Node* temp = new Node{num, nullptr, nullptr};
        head = temp;
        tail = temp;
        pNode = temp;
    } else {
        pNode = head;
        Node* temp = new Node{num, pNode, nullptr};
        head = temp;
        pNode->prev = head;
    }
}

void LinkList::insert_middle(int num, int index) {
    pNode = head;
    if (isEmpty()) {
        Node* temp = new Node{num, nullptr, nullptr};
        head = temp;
        tail = temp;
        pNode = temp;
    } else {
        for (int i = 0; i < index - 1; i++) {
            pNode = pNode->next;
        }
        Node* temp = new Node{num, pNode->next, pNode};
        pNode->next = temp;
        if(temp->next == nullptr) {
            tail = temp;
        } else if(temp->prev == nullptr) {
            head = temp;
        }
    }
}

int LinkList::remove_end() {
    pNode = tail;
    pNode->prev->next = nullptr;
    int val = pNode->val;
    delete pNode;
    return val;
}

int LinkList::remove_front() {
    pNode = head;
    head = pNode->next;
    int val = pNode->val;
    delete pNode;
    return val;
}

int LinkList::remove_middle(int index) {
    pNode = head;
    for (int i = 0; i < index - 1; i++) {
        pNode = pNode->next;
    }
    if(pNode->next == nullptr) {
        tail = pNode->prev;
        tail->next = nullptr;
    } else {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }
    int val = pNode->val;
    delete pNode;
    return val;
}

int LinkList::size() {
    int count = 0;
    pNode = head;
    while(pNode != nullptr) {
        pNode = pNode->next;
        count++;
    }
    return count;
}

void LinkList::makeEmpty() {
    pNode = head;
    Node* temp;
    while(pNode != nullptr) {
        temp = pNode->next;
        delete pNode;
        pNode = temp;
    }
    delete pNode;
    head = nullptr;
    tail = nullptr;
}

void LinkList::printList() {
    pNode = head;
    while(pNode != nullptr) {
        cout << " " << pNode->val;
        pNode = pNode->next;
    }
    cout << endl;
}