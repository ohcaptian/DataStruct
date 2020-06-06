//
// Created by 17694 on 2020/6/6.
//
/*
 * des 二叉排序树的相关操作
 */
#include <iostream>
using namespace std;
typedef int Datatype;
#define SUCCESS 0;
typedef struct BSTNode{
        Datatype data;
        struct BSTNode *lChild,*rChild;
}BSTNode,*BST;

int InsertBST(BST &p,Datatype data);//结点的插入
BST CreateBST(Datatype A[], int n);//生成排序二叉树
void in_Travel(BST tree);//中序遍历二叉树
BST SearchBST(BST t, int k);//查找目标结点
void print(BST t);//输出目标结点
bool deleteNode(BST &b);
bool deleteTree(BST &b, int key);
int main(){
    int key,n;
    BST tree,temp;
    cout<<"请输入结点的个数"<<endl;
    cin>>n;
    int data[n];
    cout<<"要输入的数据"<<endl;
      for(int i=0;i<n;i++){
          cin>>data[i];
      }
        tree = CreateBST(data,n);
        in_Travel(tree);
        cout<<endl<<"请输入要查找的元素"<<endl;
        cin>>key;
       temp =SearchBST(tree,key);
        print(temp);
        cout<<endl<<"==========华丽的分隔符==============="<<endl;
    cout<<"请输入要删除的元素"<<endl;
        cin>>key;
        if( deleteTree(tree,key))
            in_Travel(tree);
        else{
            cout<<"要删除的元素不存在"<<endl;
            in_Travel(tree);
        }

}
int InsertBST(BST &p,Datatype data)
{
    //如果二叉树为空，生成一个首节点,左右儿子置空
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
//查找结点
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
        cout<<"不存在该值"<<endl;
        return;
    } else{
        cout<<"存在该值"<<" "<<t->data;
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
