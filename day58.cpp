#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//1
class CircularQueueVec {
    vector <int>arr;
    int front,rear,count,capacity;
public:
    CircularQueueVec(int cap): arr(cap),front(0),rear(-1),count(0),capacity(cap) {}
    //2
    bool enqueue(int val) {
        if (count==capacity) return false;
        rear=(rear+1)% capacity;
        arr[rear]=val;
        count++;
        return true;
    } 
    //3
    int dequeue() {
        if (count==0) return -1;
        int val=arr[front];
        front = (front+1)% capacity;
        count--;
        return val;
    }
};
//6
//circular buffer for a fixed-size rolling log (last n events) 
class RollingLog {
    vector<string>buffer;
    int index=0;
    int capacity;
public:
    //7
    RollingLog(int cap) : capacity(cap),buffer(cap,"") {}
    //8
    void addLog(string event) {
        buffer[index]=event;
        index=(index+1)% capacity;
    }
    //9
    void printLogs() {
        for (auto& e:buffer) if (!e.empty()) cout<<e<<endl;
    }
};
int main() {
    //4
    CircularQueueVec q(4);
    q.enqueue(1);q.enqueue(2);q.enqueue(3);
    cout<<q.dequeue()<<endl;
    q.enqueue(4);q.enqueue(5);
    cout<<q.dequeue()<<endl;
    //5
    // Simulating a printer Queue ( real word case)
    queue<string>printerQueue;
    printerQueue.push("Document1.pdf");
    printerQueue.push("Document2.pdf");
    printerQueue.push("Document3.pdf");
    while (!printerQueue.empty()){
        cout<<"Printing:"<<printerQueue.front()<<endl;
        printerQueue.pop();
    }
    //10
    RollingLog log(3);
    log.addLog("Login");
    log.addLog("ClickButton");
    log.addLog("Logout");
    log.addLog("Login2");
    log.printLogs();    
}