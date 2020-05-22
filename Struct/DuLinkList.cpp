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
    Node(T v, Node *n, Node *p){
        this->data=v;
        this->next=n;
        this->prev=p;
    }

};
template<typename T>
class MyDuLinkList{
public:
        int size;
        Node<T> *head;
        Node<T> *tail;
public:
    MyDuLinkList(){
        head = nullptr;
        tail = nullptr;
        size=0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index){
        Node<T>* cur = head;
            if(index>size||index<0){
                cout<<"ERROR"<<endl;
                return 1;
            }
            for(int i=0;i<index;i++){
                cur = cur->next;
            }
            cout<<cur->data;
            return 0;
    }


    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(T val) {
                if(!head){
                    head = new Node<T>(val,nullptr, nullptr);
                    tail  =head;
                } else{
                    Node<T>* temp  = new Node<T>(val, head, nullptr);
                    head->prev = temp;
                    head = temp;
                }
                    size++;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(T val) {
             if(!head){
                 head = new Node<T>(val,nullptr, nullptr);
                 tail  =head;
             } else{
                 Node<T>* temp = new Node<T>(val, nullptr,tail);
                 tail->next = temp;
                 tail = temp;
             }
            size++;
    }


    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
                if(!head||index>size){
                    cout<<"ERROR"<<endl;
                    return;
                }
                Node<T> *cur = head;
                Node<T>*pre = nullptr;
                int temp =0;
                while(cur){
                    if(index==temp){
                        Node<T>* newNode = new Node<T>(val,cur,pre);
                        if (pre != nullptr) pre->next = newNode;
                        cur->prev = newNode;
                        size++;
                        return;
                    }
                    pre = cur;
                    cur = cur->next;
                    temp++;
                }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>size||!head){
            cout<<"ERROR"<<endl;
            return;
        }
        int temp=0;
        Node<T>* cur  = head;
        Node<T>* pre;
        while(cur){
            if(temp==index){
                Node<T> *old = cur;
                if (pre!= nullptr) pre->next = cur->next;
                if (cur->next != nullptr) cur->next->prev = pre;
                delete old;
                size--;
                return;
            }
            temp++;
            pre = cur;
            cur = cur->next;
            temp++;
        }



    }

    void display(){
                Node<T>* cur ;
                cur = this->head;
                while(cur){
                    cout<<cur->data<<" ";
                    cur = cur->next;
                }
                cout<<endl;
    }
};
int main(){
    MyDuLinkList<int> duList;
    duList.addAtHead(1);
    duList.addAtHead(3);
    duList.addAtHead(88);
    duList.addAtTail(199);
    duList.display();
    duList.addAtIndex(1,7);
    duList.display();
    duList.deleteAtIndex(2);
    duList.display();
    duList.get(3);
}