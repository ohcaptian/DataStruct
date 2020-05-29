//
// Created by 17694 on 2020/5/29.
//
#include <iostream>
using namespace std;
void Swap(int &a,int &b){
    int temp =a;
    a =b;
    b =temp;
}
void Select(int *a,int n,int &m1,int &m2){
    m1 = a[0];//假设第一个值为最小值;
    m2 = m1;
    for(int i=1;i<n;i++) {
            if (a[i] < m2) {
                m2 = a[i];
            }
            if (m2 < m1) {
                Swap(m1, m2);
            }
    }
}

int main(){
    int m1,m2;
        int a[] = {4,2,7,3,8,4,23};
        Select(a,7,m1,m2);
        cout<<m1<<" "<<m2;
}

