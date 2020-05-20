//
// Created by 17694 on 2020/5/17.
//

#include <iostream>
using namespace std;
#define OVERFLOW -1
#define OK 0
#define ERROR 1
#define MAXSIZE 100
#define ElemType int
#define Status int
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
int InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
    {
        return ERROR;
    }
    L.length = 0;
    return OK;
}
Status CreateList(SqList &L,int n){
    if(!L.elem){
        return ERROR;
    }
    for(int i=0;i<n;i++){
        L.elem[i] = i;
        L.length++;
    }


}
Status GetElem(SqList L, int i, ElemType e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}
Status LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
Status ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length+1)
    {
        cout<<"ERROR"<<endl;
        return ERROR;
    }
    //j  数组下标;  i 数组下标;
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}
Status ListDelete(SqList &L, int i)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    for (int j = i; j <=L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    --L.length;
    return OK;
}
Status ListPrint(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d", L.elem[i]);
    }
    cout<<endl;
    return OK;
}
int main()
{
    int n=10;
    SqList L;
    InitList(L);
    CreateList(L,n);//长度为4
    ListPrint(L);
   ListInsert(L,1,10);
       // ListInsert(L, i, i);
    ListPrint(L);
    ListDelete(L, 3);
    ListPrint(L);
    return 0;
}