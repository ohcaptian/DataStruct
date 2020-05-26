//
// Created by 17694 on 2020/5/26.
//
/*
 * des create HuffmanTree
 */
#include<iostream>
using namespace std;
//线性存储方式
typedef struct Node{
    int weight;
    int parent ,lchild,rchild;
    static int  number;//HuffMan树的叶子结点个数
}HFNode,*HuffMan;

void CreateHuffMan(HuffMan ht,int n){
    int m = 2*n;
    ht = new HFNode[m];
    ht->number=n;
    for(int i=1;i<m;i++){
       ht[i].parent=ht[i].lchild=ht[i].rchild=0;
    }

    //输入n个结点的权值
    for(int i=1;i<n+1;i++){
            cin>>ht[i].weight;
    }
    //将剩余的n-1个结点用来构建二叉树;
    for(int i=n+1;i<m;i++){


    }
    
    
    
}
/*
 * des 从数据中挑选出两个最小的数
 */
//s1 ,s2 作为返回结点的下标;
void Select(HuffMan ht,int &s1,int &s2){
        int m1,m2;//作为保存最小值的变量
    for(int i=1;i<ht->number;i++)
            if(ht[i].parent==0){

            }
}