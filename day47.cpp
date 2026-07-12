//leetcode =347
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
class solution347 {
    public:
    vector<int>top_K_frequent_element(vector<int>& nums,int k){
        unordered_map<int,int>freq;
        for (int num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for (auto& entry:freq){
            minHeap.push({entry.second,entry.first});
            if (minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        } return result;
    }
}; 
class solution78 {
    public:
    void backtrack(int index,vector<int>& nums,vector<int>& path,vector<vector<int>>& result){
        if (index==nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        backtrack(index+1,nums,path,result);
        path.pop_back();
        backtrack(index+1,nums,path,result);
    }
    vector<vector<int>>subsets(vector<int>& nums){
        vector<vector<int>>result;
        vector<int>path;
        backtrack(0,nums,path,result);
        return result;
    }
};