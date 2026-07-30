//
//count subarray withsum =x(basic)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//560
int countSubarray(vector<int>&nums1,int k){
    unordered_map<int,int>mp;
    mp[0]=1;

    int prefix=0;
    int ans=0;

    for (int x:nums1){
        prefix+=x;

        if (mp.count(prefix-k)){
            ans+=mp[prefix-k];
        }
        mp[prefix]++;
    }
    return ans;
};
//longest subarray with sum =k
//nums=[1,-1,5,-2,3]
//k=3
//ans=4
//325
int longestSubarray(vector<int>&nums2,int k){
    unordered_map<int,int>firstIndex;
    firstIndex[0]=-1;
    int prefix=0;
    int ans=0;

    for(int i=0;i<(int)nums2.size();++i){

        prefix+=nums2[i];

        if(firstIndex.count(prefix-k)){
            ans=max(ans,i-firstIndex[prefix-k]);
        }

        if(!firstIndex.count(prefix)){
            firstIndex[prefix]=i;
        }
    }
    return ans;
};
//count Subarray Divisible by k
//nums=[4,5,0,-2,-3,1]
//k=5
//ans=7
//974
int subarrayDivbyk(vector<int>&nums3,int k){
    unordered_map<int,int>mp;
    mp[0]=1;

    int prefix=0;
    int ans=0;

    for(int x:nums3){
        
        prefix+=x;
        int rem=((prefix%k)+k)%k;

        if(mp.count(rem)){
            ans+=mp[rem];
        }

        mp[rem]++;
    }

    return ans;
};
//binary subarrays with sum
//nums=[1,0,1,0,1]
//answer=4
//930
int numsubarraywithsum(vector<int>&nums4,int goal){

    unordered_map<int,int>mp;
    mp[0]=1;

    int prefix=0;
    int ans=0;

    for (int x:nums4){

        prefix+=x;

        if (mp.count(prefix-goal)){
            ans+=mp[prefix-goal];
        }

        mp[prefix]++;
    }

    return ans;
}

//count equal number of 0s and 1s
//nums=[1,0,1,0]
//answer=4

int equalzeroone(vector<int>&nums5){

    unordered_map<int,int>mp;
    mp[0]=1;

    int prefix=0;
    int ans=0;

    for(int x:nums5){
        if (x==0){
            prefix-=1;
        } else {
            prefix+=1;

        }

        if(mp.count(prefix)){
            ans+=mp[prefix];
        }

        mp[prefix]++;
    }

    return ans;
};
//525
//Contigious array
class Solution525 {
public:
    int findMaxLength(vector<int>& nums) {
    unordered_map<int,int>firstIndex;
    firstIndex[0]=-1;

    int prefix=0;
    int ans=0;

    for(int i=0;i<(int)nums.size();++i){

        prefix+=(nums[i]==0) ? -1:1;

        if(firstIndex.count(prefix)){
            ans=max(ans,i-firstIndex[prefix]);
        }

        if(!firstIndex.count(prefix)){
            firstIndex[prefix]=i;
        }
    }
    return ans;
    }
};

//output for all 5

int main() {
    vector<int>nums1={1,2,3,-2,5};
    cout<<"First answer is: "<<countSubarray(nums1,3)<<endl;

    cout<<endl;

    vector<int>nums2={1,-1,5,-2,3};
    cout<<"Second answer is:"<<longestSubarray(nums2,3)<<endl;

    cout<<endl;


    vector<int>nums3={4,5,0,-2,-3,1};
    cout<<"Third answer is: "<<subarrayDivbyk(nums3,5)<<endl;

    cout<<endl;

    vector<int>num4={1,0,1,0,1};
    cout<<"Fourth answer is: "<<numsubarraywithsum(num4,2)<<endl;

    cout<<endl;

    vector<int>nums5={1,0,1,0};
    cout<<"Fifth answer is: "<<equalzeroone(nums5)<<endl;

    cout<<endl;
}