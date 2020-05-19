//
// Created by 17694 on 2020/5/12.
//
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next= nullptr;
    }
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList();
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index);

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val);
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val);

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val);

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index);
    void display();
    void listLength();
private:
    Node *head;
    int size;
};

int main(){
    MyLinkedList *linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList->display();
    cout<<endl;
   int temp =  linkedList->get(1);            //返回2
   cout<<temp<<endl;
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->display();
    temp = linkedList->get(1);
    cout<<endl;
    cout<<temp;
}
//初始化，不带头结点;
MyLinkedList::MyLinkedList() {
    head = nullptr;
    size=0;
}
//Head insetr;
void MyLinkedList:: addAtHead(int val){
    Node* temp  = head;
    if(!head){
        Node *ptrnode = new Node(val);
        head=ptrnode;
        size++;
    }
    else
    {
        Node *ptrnode = new Node(val);
        ptrnode->next = temp;
        head = ptrnode;
        size++;
    }
}
//Tail insetr;
void MyLinkedList::addAtTail(int val) {
    if(!head) {
        Node *ptrnode = new Node(val);
        head = ptrnode;
        size++;
    }
    Node* temp = this->head;
    Node* pre;//记录最后一个指针的前面一个值;
    while (temp){
        pre = temp;
        temp = temp->next;
    }
    Node *ptrnode = new Node(val);
    pre->next=ptrnode;
    size++;
    delete temp;
}
void MyLinkedList::addAtIndex(int index, int val) {
    Node* temp = this->head;
        if(index>size){
            cout<<"not be inserted"<<endl;
            return;
        } else if(index==size)
        {
            addAtTail(val);
            Node *ptrnode = new Node(val);
            Node* pre;
            while(temp)
            {
                pre = temp;
                temp=temp->next;
            }
            pre->next = ptrnode;
                  size++;
        } else{
            for(int i=0;i<index-1;i++)
            {
                temp = temp->next;
            }
                Node *ptrnode  = new Node(val);
                ptrnode->next=temp->next;
                temp->next = ptrnode;
                size++;
        }

}
// 1 2 3;删除2;
void MyLinkedList::deleteAtIndex(int index) {
        Node* temp = head;
        Node* p;
            if(index>size)
            {
                cout<<"index is not value"<<endl;
                return;
            }
            for(int i=0;i<index-1;i++)
            {
               temp = temp->next;
            }
            Node* t = temp->next;
            p = temp->next;
            temp->next =p->next;
            delete t;//删除这个结点：
}
int MyLinkedList::get(int index){
    Node* temp = this->head;
        if(!head||index>size){
            cout<<"empty or index is invalid"<<endl;
            return -1;
        }
       for(int i=1;i<=index;i++){
           temp=temp->next;
       }
       return temp->val;
}
void MyLinkedList::display() {
    Node* temp =this->head;
    while(temp)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}
void MyLinkedList::listLength() {
    cout<<this->size<<endl;
}