//
// Created by 17694 on 2020/5/20.
//
#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next,*head;
    int size;
}*MyLinkedList,Node;
void myLinkListInit(MyLinkedList obj);
int myLinkedListGet(MyLinkedList obj, int index);
void myLinkedListAddAtHead(MyLinkedList obj, int val);
void myLinkedListAddAtIndex(MyLinkedList obj, int index, int val);
void myLinkedListFree(MyLinkedList obj);
void myLinkedListAddAtTail(MyLinkedList obj, int val);
int mian(){


}
void myLinkListInit(MyLinkedList &obj){
    obj = new Node();
    if(!obj){
        cout<<"ERROR"<<endl;
        return;
    }
    cin>>obj->data;
    obj->next=nullptr;
    obj->head= nullptr;
    obj->size=0;

}
int myLinkedListGet(MyLinkedList &obj, int index) {

}
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList obj, int val) {

}
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList obj, int val) {

}
/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList obj, int index, int val) {

}
/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList obj, int index) {

}
void myLinkedListFree(MyLinkedList obj) {

}
void display(MyLinkedList obj){
    if(obj == NULL)
    {
       cout<<"输入的链表信息有误，链表不存在!"<<endl;
    }
    else
    {
        Node *p;
        p = obj;
        while(p!= NULL)
        {
          cout<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
}