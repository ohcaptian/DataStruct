//
// Created by 17694 on 2020/5/19.
//
#include<iostream>
using namespace std;
template<typename T>
class DuLinkListNode{
    T data;
    DuLinkListNode *prev,*next;
};
template<typename T>
class MyDuLinkList{
    private:
        int size;
        DuLinkListNode<T> *phead;
public:
    MyDuLinkList();

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index);


    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(T val) ;

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(T val) ;


    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) ;

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) ;

};
template<typename T>
MyDuLinkList<T>:: MyDuLinkList(){
    phead = new DuLinkListNode<T>();
    phead->prev = phead->next = phead;
    size=0;
}
template<typename T>
void MyDuLinkList<T>::addAtTail(T val) {
    DuLinkListNode<T>* temp;
    DuLinkListNode<T>* neNode;
        phead->next = temp;
        if(!temp)
        {
            neNode = new DuLinkListNode<T>();
            neNode->data = val;
            neNode->next = phead;
            neNode->prev = temp;
            phead->next  =neNode;

        }
        neNode = new DuLinkListNode<T>();
        neNode->data = val;
        neNode->next
}

