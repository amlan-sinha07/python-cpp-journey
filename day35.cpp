#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char ,int > seen ;
        for (char x: ransomNote){
            seen[x]++ ;
        }
        for (char x: magazine){
            seen[x]-- ;
        }
        for (auto& pair: seen){
            if (pair.second > 0){
                return false;
            }
            
            
        }
        return true;
    }
};