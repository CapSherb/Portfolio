//
// Created by richj on 5/23/2023.
//

#ifndef COP3530HW1_LINKLIST_H
#define COP3530HW1_LINKLIST_H


/**
 * Dynamic Doubly Linked List class
 * Insert Functions: end, front, middle
 * Remove Functions: end, front, middle
 * Misc Functions: isEmpty, size, makeEmpty, print
 */
class LinkList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    Node* pNode;


public:
    /**
     * Default constructor
     * Creates empty list w/ head = nullptr and tail = nullptr
     */
    LinkList() {
        head = nullptr;
        pNode = nullptr;
        tail = nullptr
    };

    /**
     * Checks if list is empty
     * @return True if empty; False if it has elements
     */
    bool isEmpty();

    /**
     * Appends a number to the end of the list
     * @param num Number to append to end of list
     */
    void insert_end(int num);

    /**
     * Inserts a number at the beginning, or head, of a list
     * @param num Number to insert as new head of list
     */
    void insert_front(int num);

    /**
     * Inserts a number into a selected index of the list, including head and tail
     * @param num Number to insert into list
     * @param index Index where element will be inserted
     */
    void insert_middle(int num, int index);

    /**
     * Removes and frees memory of element at the end of a list
     * @return Value of element being deleted
     */
    int remove_end();

    /**
     * Removes and frees memory of element at the front of a list
     * @return Value of element being deleted
     */
    int remove_front();

    /**
     * Removes and frees memory of an element at selected index in a list
     * @param index Index of element to be deleted
     * @return Value of element being deleted
     */
    int remove_middle(int index);

    /**
     * Checks and returns size of list as an int
     * @return Number of elements(size) of a list
     */
    int size();

    /**
     * Empties and deletes memory of all elements in a list
     */
    void makeEmpty();

    /**
     * Traverses and prints every element of a list from head to tail
     */
    void printList();

};

#endif //COP3530HW1_LINKLIST_H
