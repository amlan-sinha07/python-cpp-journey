//lc=46
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class solution46{
    public:
    void backtrack(vector<int>&nums,vector<int>&path,vector<bool>&used,vector<vector<int>>result){
        if ((int)nums.size()==(int)path.size()){
            result.push_back(path);
            return;
        }
        for (int i=0;i<(int)nums.size();++i){
            if (used[i]==true)continue;
            used[i]=true;
            path.push_back(used[i]);
            backtrack(nums,path,used,result);
            path.pop_back();
            used[i]=false;
        }

    }
    vector<vector<int>>permute(vector<int>&nums){
        vector<int>path;
        vector<bool>used(nums.size(),false);
        vector<vector<int>>result;
        backtrack(nums,path,used,result);
        return result;
    }
};
class solution704{
    public:
    int search(vector<int>&nums,int target){
        int left=0;
        int right=(int)nums.size()-1;
        while (left<right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target){return mid;}
            else if (nums[mid]>target){right=mid-1;}
            else if (nums[mid]<target){left=mid+1;}
        } return -1;
    }
};
class solution278{
    public:
    bool isbadversion(int version){}
        int firstbadversion(int n){
            int left=1;
            int right=n;
            while (left<=right){
                int mid=left+(right-left)/2;
                if (isbadversion(mid)){right=mid;}
                else {left=mid+1;}
            } return left;
        }
};
class solution977{
    public:
    vector<int>sortedsquares(vector<int>&nums){
        vector<int>result(nums.size());
        int left=0;
        int right=(int)nums.size()-1;
        int pos=(int)nums.size()-1;
        while(left<=right){
            if (abs(nums[left])>=abs(nums[right])){
                result[pos]=nums[left]*nums[left];
                left++;
            }
            else {
                result[pos]=nums[right]*nums[right];
                right--;
            }
            pos--;
        } return result;
    }
};