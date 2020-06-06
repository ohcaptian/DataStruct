//
// Created by 17694 on 2020/6/6.
//
/*
 * des ��������������ز���
 */
#include <iostream>
using namespace std;
typedef int Datatype;
#define SUCCESS 0;
typedef struct BSTNode{
        Datatype data;
        struct BSTNode *lChild,*rChild;
}BSTNode,*BST;

int InsertBST(BST &p,Datatype data);//���Ĳ���
BST CreateBST(Datatype A[], int n);//�������������
void in_Travel(BST tree);//�������������
BST SearchBST(BST t, int k);//����Ŀ����
void print(BST t);//���Ŀ����
bool deleteNode(BST &b);
bool deleteTree(BST &b, int key);
int main(){
    int key,n;
    BST tree,temp;
    cout<<"��������ĸ���"<<endl;
    cin>>n;
    int data[n];
    cout<<"Ҫ���������"<<endl;
      for(int i=0;i<n;i++){
          cin>>data[i];
      }
        tree = CreateBST(data,n);
        in_Travel(tree);
        cout<<endl<<"������Ҫ���ҵ�Ԫ��"<<endl;
        cin>>key;
       temp =SearchBST(tree,key);
        print(temp);
        cout<<endl<<"==========�����ķָ���==============="<<endl;
    cout<<"������Ҫɾ����Ԫ��"<<endl;
        cin>>key;
        if( deleteTree(tree,key))
            in_Travel(tree);
        else{
            cout<<"Ҫɾ����Ԫ�ز�����"<<endl;
            in_Travel(tree);
        }

}
int InsertBST(BST &p,Datatype data)
{
    //���������Ϊ�գ�����һ���׽ڵ�,���Ҷ����ÿ�
    if(p==NULL)
    {
        p=new BSTNode();
        p->data=data;
        p->lChild=p->rChild=NULL;
        return SUCCESS;
    }
    else if(data==p->data)
        return 0;
    else if(data<p->data)
        return InsertBST(p->lChild,data);
    else
        return InsertBST(p->rChild, data);
}
BST CreateBST(Datatype A[], int n)
{
    BST bt=NULL;
    int i=0;
    while(i<n)
    {
        InsertBST(bt, A[i]);
        i++;
    }
    return bt;
}
void in_Travel(BST tree){
        if(!tree){
            return;
        }
    in_Travel(tree->lChild);
    cout<<tree->data<<" ";
    in_Travel(tree->rChild);
}
//���ҽ��
BST SearchBST(BST t, int k)
{
    if(t==NULL || k==t->data)
        return t;
    else if(k<t->data)
        return SearchBST(t->lChild, k);
    else
        return SearchBST(t->rChild, k);
}
void print(BST t){
    if(!t){
        cout<<"�����ڸ�ֵ"<<endl;
        return;
    } else{
        cout<<"���ڸ�ֵ"<<" "<<t->data;
    }

}
bool deleteNode(BST &b);
bool deleteTree(BST &b, int key){
    if (!b)
        return false;
    else {
        if (b->data == key) {
            return deleteNode(b);
        } else if (b->data > key)
            return deleteTree(b->lChild, key);
        else
            return deleteTree(b->rChild, key);
    }
}

bool deleteNode(BST &b) {
    BST p, s;
    if (b->lChild == NULL) {
        p = b;
        b = b->rChild;
        delete p;
    } else if (b->rChild == NULL) {
        p = b;
        b = b->lChild;
        delete p;
    } else {
        p = b;
        s = b->lChild;
        while (s->rChild != NULL) {
            p = s;
            s = s->rChild;
        }
        b->data = s->data;
        if (p != b)
            p->rChild = s->lChild;
        else
            p->lChild = s->lChild;
        delete s;
        return true;
    }
}
