#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution128 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> seen;
        for (int x=0;x<(int)nums.size();++x){
        seen.insert(nums[x]);
        }
        int length=0;
        for (int num:seen){
            if (seen.count(num-1)==0){
                int currentNum=num;
                int currentLength=1;
                while (seen.count(currentNum+1)==1){
                    currentNum++;
                    currentLength++;
                }
                length=max(length,currentLength);
            }
        }
        return length;
    }
};
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for (int i=0;i<(int)nums.size()-2;++i){
            if ( i>0 && nums[i]==nums[i-1]){
                continue;}
            int left=i+1;
            int right=(int)nums.size()-1;
            while (left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if (sum==0){
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){left++;}
                    while (left<right && nums[right]==nums[right+1]){right--;}
                }
                else if (sum<0){
                    left++;
                }
                else {right--;}
            }
        } return result;
    }
};