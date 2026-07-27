#include <iostream>
#include <queue>
//18
#include <vector>

using namespace std;
class Queue {
private:
    int *arr;
    int frontindex;
    int rearindex;
    int capacity;
public:
//1    
    Queue(int size) {
        capacity=size;
        arr=new int[capacity];
        frontindex=0;
        rearindex=-1;
    }
//2
    bool isempty() {
        return rearindex<frontindex;
    }
    //3
    bool isfull() {
        return rearindex==capacity-1;
    }
    //4
    void enqueue(int x) {
        if (isfull()) {
            cout<<"queue is full\n";
            return;
        }
        rearindex++;
        arr[rearindex]=x;
    }
    //5
    void dequeue() {
        if (isempty()) {
            cout<<"queue is empty\n";
            return;
        }
        cout<<"removed: "<<arr[frontindex]<<endl;
        frontindex++;
    }
    //6
    int front() {
        if (isempty()) {
            cout<<"queue is empty\n";
            return -1;
        }
        return arr[frontindex];
    }
    //7
    void display() {
        if (isempty()) {
            cout<<"queue is empty\n";
            return;
        }
        for (int i=frontindex; i<=rearindex; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //8
    ~Queue() {
        delete[] arr;
    }
    //10
    void cyclicenqueue(int x) {
        if (isfull()) {
            cout<<"queue is full\n";
            return;
        }
        int count=0;
        rearindex=(rearindex+1)%capacity;
        arr[rearindex]=x;
        count++;
    }
};
//basic circular queue class qith enqueue and dequeue
//11
class CircularQueue {
    int *arr;
    int front , rear , size , capacity ;
public:
    //12
    CircularQueue (int cap) {
        capacity=cap;
        arr= new int[capacity];
        front= -1;
        rear= -1;
        size= 0;
    }
    //13
    bool enqueue(int val) {
        if (size==capacity) return false;
        if (front == -1) front =0;
        rear= (rear+1) % capacity;
        arr[rear]=val;
        size++;
        return true;
    }
    //14
    bool dequeue() {
        if (size==0) return false;
        front = (front+1)% capacity;
        size--;
        if (size==0) {front=-1, rear=-1;}
        return true;
    }
    //15
    int Front() {
        return size==0 ? -1: arr[front];
    }
    //16
    int Rear() {
        return size==0 ? -1 : arr[rear];
    }
};
//19
class CircularQueueVector {
    vector<int>arr;
    int front,rear,count , capacity;
public:
//20
    CircularQueueVector(int cap):
    arr(cap),front(0),
    rear(-1),count(0),
    capacity(cap) {}
};
int main() {
    //9
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.cyclicenqueue(1);
    q.display();
    q.front();
    q.dequeue();
    q.front();
    q.isempty();
    q.isfull();
    q.display();
    cout<<endl;
    //17
    CircularQueue cq(3);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cout<<"Front: "<<cq.Front()<<", Rear: "<<cq.Rear()<<endl;
    cq.dequeue();
    cq.enqueue(4);
    cout<<"front: "<<cq.Front()<<", Rear: "<<cq.Rear()<<endl;
}