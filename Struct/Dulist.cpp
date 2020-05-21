//
// Created by 17694 on 2020/5/20.
//
#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next,*prve;
    int size;
}*MyLinkedList,Node;
void myLinkListInit(MyLinkedList &obj,int n);
int myLinkedListGet(MyLinkedList obj, int index);
void myLinkedListAddAtHead(MyLinkedList &obj, int val);
void myLinkedListAddAtIndex(MyLinkedList &obj, int index, int val);
void myLinkedListFree(MyLinkedList obj);
void myLinkedListAddAtTail(MyLinkedList obj, int val);
void display(MyLinkedList obj);
int main(){
    int val = 8;
    int n=4;
    MyLinkedList list;
    myLinkListInit(list,n);
    myLinkedListAddAtHead(list,val);
    display(list);
}
void myLinkListInit(MyLinkedList &head,int n){
    int x;
    head = new Node();
    MyLinkedList p,s;
    if(!head){
        cout<<"ERROR"<<endl;
        return;
    }
    p = head;
    p->prve=NULL;
    while(n){
        s = new Node();
        if(!s){
            cout<<"ERROR"<<endl;
            return;
        }
        cin>>s->data;
        p->next=s;
        s->prve=p;
        p=s;
        n--;
    }
    s->next=NULL;
    return;
}
int myLinkedListGet(MyLinkedList &obj, int index) {

}
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList &obj, int val) {
            MyLinkedList head = obj->next;
            MyLinkedList temp = new Node();
            if(!temp){
                cout<<"ERROR"<<endl;
                return;
            }
            temp->data=val;
            temp->next = obj->next;
            temp->prve = obj;
            if (NULL != temp->next) {
                    temp->next->prve = temp;
                }
            obj->next = temp;
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
    MyLinkedList temp = obj->next;
    if(temp == NULL)
    {
       cout<<"输入的链表信息有误，链表不存在!"<<endl;
        return;
    }
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}