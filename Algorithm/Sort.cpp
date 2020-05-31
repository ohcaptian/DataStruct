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
void Insert_Sort(int elem[],int length);
void Select_Sort(int elem[],int length);
void Merge_Sort(int elem[],int length);
void display(int elem[],int length);
int main(){
    int length=10;//排序数组大小
    int elem[10]={2,5,675,8,21,66,22,12,54,87};
    //Bubble_Sort(elem,length);
    //Insert_Sort(elem,length);
    //Select_Sort(elem,length);
    Merge_Sort(elem,length);
    display(elem,length);

}
void display(int elem[],int length){
    for(int i=0;i<length;i++){
        cout<<elem[i]<<" ";
    }
    cout<<endl;
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
void Insert_Sort(int elem[],int length){
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
/*
 * des 从数组中挑选最小的放入第一个位置。循环操作
 */
void Select_Sort(int elem[],int length){
            for(int i=0;i<length;i++){
                int min = i;//假定的最小值的位置;
                for(int j=i+1;j<length;j++){
                    if(elem[j]<elem[min]){
                        min =j;
                    }
                }
                int temp = elem[min];
                elem[min]=elem[i];
                elem[i]=temp;
            }
    display(elem,length);
}
void Merge(int *a,int *temp,int l,int r,int rightend);
void Msort(int *a,int *temp,int left,int rightend);
void Msort(int *a,int left,int rightend);
void Merge_Sort(int elem[],int length){
            int *temp = new int[10];
            if(temp){
                Msort(elem,temp,0,length-1);
                delete temp;
            } else
                cout<<"ERROR";
    return;

}
void Msort(int *a,int *temp,int left,int rightend){
                int center;
                if(left<rightend) {
                    center = (left +rightend) / 2;
                    Msort(a, temp, left, center);
                   Msort(a, temp, center+1, rightend);
                    Merge(a, temp,left,center + 1, rightend);
                }
}
void Merge(int *a,int *temp,int l,int r,int rightend){
        int leftend = r-1;
        int tem = l;
        int numelem = rightend-l+1;
        while(l<=leftend&&r<=rightend){
                    if(a[l]<a[r]){
                        temp[tem++] = a[l++];
                    } else temp[tem++] = a[r++];
        }
           while(l<=leftend){
               temp[tem++] = a[l++];
           }
           while(r<=rightend){
               temp[tem++] = a[r++];
           }
           for(int i=0;i<numelem;i++,rightend--){
               a[rightend]=temp[rightend];
           }
}