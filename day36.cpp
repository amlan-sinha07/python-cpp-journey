#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution136 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> seen;
        for (int x : nums){
            seen[x]++ ;
        }
        for (auto& pair : seen){
            if (pair.second==1){
                return pair.first;
            }
        } return 0;
    } 
};
class Solution136 {
public:
    int singleNumber(vector<int>& nums) {
        int accumulate =0;
        for (int i=0; i<(int)nums.size(); ++i){
            accumulate ^= nums[i];
        } return accumulate;
    } 
};
class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size() - 1;
        while (left <= right){
            int mid= (left + right)/2;
            if (nums[mid]==target) {return mid;}
            else if (nums[mid]> target) { right=mid-1;}
            else if (nums[mid]< target) { left=mid+1;}
        } return -1;
    }
};