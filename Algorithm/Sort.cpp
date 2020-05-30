//
// Created by 17694 on 2020/5/25.
//

/*
 * des  排序算法
 */
#include <iostream>
using namespace std;
#define  SWAP(a,b)     {int temp = a;a=b;b=temp;}
void Bubble_Sort(int elem[],int length);
void insert_sort(int elem[],int length);
int main(){
    int length=10;//排序数组大小
    int elem[10]={2,5,675,8,21,66,22,12,54,87};
    //Bubble_Sort(elem,length);
    insert_sort(elem,length);
}

//冒泡拍序
void Bubble_Sort(int elem[],int length){

        for(int i=0;i<length-1;i++){
            for(int j=0;i<length-1-j;j++){
                if(elem[j]>elem[j+1]){
                    SWAP(elem[j],elem[j+1]);
                }
            }
        }
        for(int i=0;i<length;i++){
            cout<<elem[i]<<" ";
        }
        cout<<endl;
}
//插入排序
void insert_sort(int elem[],int length){
    int j;
    for(int i=1;i<length;i++){
        int temp = elem[i];
        // 插入 每次从数组中取出一个数
        /*
         * 从当前有的元素的最后一个开始比较
         */
       for(j=i;j>0&&elem[j-1]>temp;j--){
                    elem[j]=elem[j-1];//数组向后移;
                 }
             elem[j] = temp;
    }
    for(int i=0;i<length;i++){
        cout<<elem[i]<<" ";
    }
    cout<<endl;
}