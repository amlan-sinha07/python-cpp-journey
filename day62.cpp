// day 67 orginally
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <unordered_map>
using namespace std;
//295
class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxheap.empty() || num<maxheap.top()){
            maxheap.push(num);
        } else {
            minheap.push(num);
        }
        if (maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (maxheap.size()==minheap.size()){
            double mean=(maxheap.top()+minheap.top())/2;
            return mean;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// Day 68
 class Solution496 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;--i){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int nums:nums1){
            ans.push_back(mp[nums]);
        }
    return ans;
    }
};