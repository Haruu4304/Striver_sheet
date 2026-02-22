/*
PS : Design your implementation of the circular queue. The circular queue is a linear data structure in which the 
operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the 
first position to make a circle. It is also called "Ring Buffer".
*/

#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> arr;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value){
        if(isFull()) return false;

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }

    bool deQueue(){
        if(isEmpty()) return false;

        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front(){
        if(isEmpty()) return -1;
        return arr[front];
    }

    int Rear(){
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main(){
    MyCircularQueue q(3);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.Rear() << endl;   // 3
    cout << q.isFull() << endl; // 1 (true)

    q.deQueue();
    q.enQueue(4);

    cout << q.Rear() << endl;   // 4
}