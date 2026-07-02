#include <iostream>
#include <vector>
using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution278 {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n ;
        while ( left < right ){
            int mid = left + (right - left ) / 2;
            if (isBadVersion(mid)){right =mid;}
            else {left= mid + 1 ;}
        } return left ;
    } 
};
class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left=0;
        int right=nums.size()-1;
        int pos=nums.size()-1;
        while (right >= left){
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