#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MyCircularQueue {
    vector<int>data;
    int capacity,head,tail,size;
public:
    MyCircularQueue(int k): data(k),head(0),tail(-1),size(0),capacity(k){}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail=(tail+1)%capacity;
        data[tail]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head=(head+1)% capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1: data[head];
    }
    
    int Rear() {
        return isEmpty() ? -1: data[tail];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
vector<int>nextGreater(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for (int i=n-1;i>=0;--i){
        while (!st.empty()&& nums[st.top()]<=nums[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i]=nums[st.top()];
        }
        st.push(i);
    }
    return ans;
};
vector<int>nextSmall(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for (int i=n-1;i>=0;--i){
        while (!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i]=nums[st.top()];
        }
        st.push(i);
    }
    return ans;
};
vector<int>previousGreater(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;++i){
        while(!st.empty()&& nums[st.top()]<=nums[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i]=nums[st.top()];
        }
        st.push(i);
    }
    return ans;
}
class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;--i){
            while(!st.empty()&& temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if (!st.empty()){
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};
