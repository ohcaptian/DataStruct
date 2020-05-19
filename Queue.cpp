/*
 * Queue 实现
 */
#include<iostream>
#include<vector>
using namespace std;
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        p_head=p_tail=-1;
        data.resize(k);
        size=k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            cout<<"队列已满"<<endl;
            return false;
        }
        if(isEmpty())
            p_head=0;
        p_tail = (p_tail+1)%size;
        data[p_tail] =value;
            return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
            if(isEmpty())
                return -1;
            if(p_head==p_tail){
                p_tail=-1;
                p_head=-1;
            }
            p_head=(p_head+1)%size;
            return true;
    }

    /** Get the front item from the queue. */
    int Front() {
            if(isEmpty())
                return -1;
            return data[p_head];
    }
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        return data[p_tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
            return p_head==-1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((p_tail + 1) % size)==p_head;
    }
private:
    vector<int> data;
    int p_head;
    int p_tail;
    int size;
};
int main(){
     MyCircularQueue* obj = new MyCircularQueue(6);
//     cout<<obj->isFull();
//     cout<<obj->isEmpty();
     obj->enQueue(1);
     obj->enQueue(2);
     obj->enQueue(3);
     obj->deQueue();
     int temp =obj->Front();
     cout<<temp;
        temp = obj->Rear();
    cout<<temp;
}
