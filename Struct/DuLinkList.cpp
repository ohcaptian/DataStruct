//
// Created by 17694 on 2020/5/19.
//
#include<iostream>
using namespace std;
template<typename T>
class Node{
public:
    T data;
    Node *prev,*next;
    Node(){

    }
    Node(T val ,Node *pre = nullptr, Node *next = nullptr){
        this->data=val;
        this->prev=pre;
        this->next= next;
    }
//    DuLinkListNode(T t, DuLinkListNode *prev, DuLinkListNode *next){
//            this->data =t;
//            this->next=prev;
//            this->next=next;
//    }
};
template<typename T>
class MyDuLinkList{
public:
        int size;
        Node<T> *head;
        Node<T> *tail;
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

    void display();
};
template<typename T>
MyDuLinkList<T>:: MyDuLinkList(){
    head = new Node<T>();//带头节点链表;
    head->prev = head->next = nullptr;
    size=0;
}
template<typename T>
void MyDuLinkList<T>::addAtTail(T val) {
    Node<T>* temp;
    Node<T>* neNode;
    head->next = temp;
        neNode = new Node<T>(val);
        neNode->prev=
        head->prev = head;
        size++;
        return;

}
template<typename T>
void MyDuLinkList<T>::addAtHead(T val) {
    Node<T> *p = new Node<T>(val, head, head->next);
    head->next->prev = p;
    head->next = p;
    size++;
}
template<typename T>
void MyDuLinkList<T>::display()  {
    Node<T>* temp;
    temp = head->next;
        if(!temp){
            cout<<"List is empty";
            return;
        }
        while(temp!=head){
            cout<<temp->data<<" ";
           temp = temp->next;
        }
        cout<<endl;
}
int main(){
    MyDuLinkList<int> duList;
    duList.addAtHead(1);
    duList.addAtHead(3);
    duList.display();

}