//
// Created by 17694 on 2020/5/19.
//
template<typename T>
class DuLinkListNode{
    T data;
    DuLinkListNode *prev,*next;
};
template<class T>
class MyDuLinkList{
    private:
        int size;
        DuLinkListNode<T> *phead;
public:
    MyDuLinkList {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

    }



};

