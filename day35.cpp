#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std ;
class Solution169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int , int > seen ;
        if (!nums.empty()){
            for (int x: nums){
                seen[x]++ ;
            }
            for (auto& pair : seen ){
                if (pair.second > (int)nums.size()/2){
                    return pair.first;
                }
            }
        }return 0;
    } 
    
};