//
/*
 * 栈的表示和实现
 */
#include<iostream>
using namespace std;
//顺序栈的存储结构
typedef struct{
    int *top;
    int *base;
    int stacksize;
}SqStack;
//初始化
int InitStack(SqStack &S){
    S.base = new int[100];
    if(!S.base){
        return 0;
    }
    S.top=S.base;
    S.stacksize =100;
    return 1;
}
//入栈
int Push(SqStack &S,int e){
    if(S.top-S.base==S.stacksize){
        return 0;
    }
    *S.top++=e;
    return 1;
}
//出栈
int Pop(SqStack &S,int &e){
    if(S.top==S.base){
        return 0;
    }
    *S.top--;
    e=*S.top;//e=*--S.top;

    return 1;
}
//取栈顶元素
int GetTop(SqStack S){
    if(S.top!=S.base){
        return *(S.top-1);
    }
}
void show(SqStack &S){
  while(S.top!=S.base){
       int a=*S.base++;
      cout<<a<<" "<<endl;
  }
}
void show(SqStack &S){
    while(S.top!=S.base){
        int a=*S.base++;
        cout<<a<<" "<<endl;
    }
}
 int main(){
    SqStack S;
    InitStack(S);
    Push(S,1);
    Push(S,2);
    Push(S,3);
    show(S);
}






