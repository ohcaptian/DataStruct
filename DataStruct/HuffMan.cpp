//
// Created by 17694 on 2020/5/26.
//
/*
 * des create HuffmanTree
 */
typedef char **Huffmancode;//存储Huffman编码;
#include<iostream>
using namespace std;
#include <string.h>
//线性存储方式
typedef struct Node{
    int weight;
    int parent ,lchild,rchild;
}HFNode,*HuffMan;
void Select_three(HuffMan ht,int n,int &s1,int &s2);
void Select(HuffMan &HT, int n, int &s1, int &s2);
void Select_two(HuffMan &HT, int n, int &s1, int &s2);//另一种选择方式
void Swap(int &a,int &b);//交换两个值
void CreateHuffMan(HuffMan &ht,int n);//生成HuffMan tree
void CreateHuffManCode(HuffMan ht,Huffmancode &hc,int n);//哈夫曼编码
int main(){
    Huffmancode hc;
    HuffMan ht;int n;
    cin>>n;
        CreateHuffMan(ht,n);
        for(int i=1;i<2*n;i++){
            cout<<ht[i].weight<<" ";
        }
        cout<<endl;
    CreateHuffManCode(ht,hc,n);
    for(int i=0;i<n;i++){
        cout<<hc[i]<<endl;
    }
}
void CreateHuffMan(HuffMan &ht,int n){
    int s1,s2;
    int m = 2*n;
    ht = new HFNode[m];
    for(int i=1;i<m;i++){
       ht[i].parent=ht[i].lchild=ht[i].rchild=0;
    }

    //输入n个结点的权值
    for(int i=1;i<n+1;i++){
            cin>>ht[i].weight;
    }
    //将剩余的n-1个结点用来构建二叉树;
    for(int i=n+1;i<m;i++){
        //Select(ht,i-1,s1,s2);
        //Select_another(ht,i-1,s1,s2);
        Select_three(ht,i-1,s1,s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
    }
}
/*
 * des 从数据中挑选出两个最小的数
 */
//s1 ,s2 作为返回结点的下标;

void Select_three(HuffMan ht,int n,int &s1,int &s2){
        int m1,m2;//作为保存最小值的变量
        m1 = 999;//假设第一个值为最小值;
        m2 = m1;
        s1 = 1;
        s2 =s1;
    for(int i=1;i<=n;i++) {
        if (ht[i].parent == 0) {
            if (ht[i].weight < m2) {
                m2 = ht[i].weight;
                s2 =i;
            }
            if (m2 < m1) {
                Swap(m1, m2);
                Swap(s2,s1);
            }
        }
    }
}
void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b  = temp;
}

void Select(HuffMan &HT, int n, int &s1, int &s2)
{
    // 7 5 3 2 ; n  =4;
    int minum;
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0){
            minum = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0)
            if(HT[i].weight < HT[minum].weight)
                minum = i;
    }
    s1 = minum;
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0 && i != s1)
        {
            minum = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(HT[i].parent == 0 && i != s1)
            if(HT[i].weight < HT[minum].weight)
                minum = i;
    }
    s2 = minum;
}
//7 5 3 2 5 10 17
void Select_two(HuffMan &HT, int n, int &s1, int &s2){
                int ml,mr;
                ml = mr =999;
                for(int i=1;i<=n;i++){
                    if(HT[i].parent==0){
                        if(HT[i].weight<ml){
                            mr =ml;
                            ml = HT[i].weight;
                            s2 =s1;
                            s1 = i;
                        } else if(HT[i].weight<mr)
                            {
                            mr = HT[i].weight;
                            s2  =i;
                        }
                    }
                }
}
void CreateHuffManCode(HuffMan ht,Huffmancode &hc,int n){
            char *cd;
            hc = new char*[n+1];
            cd = new char[n];
            cd[n-1]='\0';
            for(int i=1;i<=n;i++){
                int statr = n-1;
                int c=i;int f=ht[i].parent;
                while(f!=0){
                    --statr;
                    if(ht[f].lchild==c) cd[statr]='0';
                    else cd[statr]='1';
                    c=f;f = ht[f].parent;
                }
                hc[i] = new char[n-statr];
                strcpy(hc[i],&cd[statr]);
            }
            delete cd;
}