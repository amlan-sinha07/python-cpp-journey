#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class solution1 {
    public :
    vector<int> twosum(vector<int>& nums, int target){
        unordered_map <int ,int > seen ;
        for (int q=0 ; q < (int)nums.size() ; ++q) {
            int complement = target - seen[q] ;
            if (seen.count(complement)) {
                return {seen[complement] , q};
            }
            seen[nums[q]] = q ;
        } return {} ;
    }
};
class Solution217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> arr ;
        for (int i=0; i<(int)nums.size(); ++i){
            if (arr.count(nums[i])){
                return true;
            }
            arr.insert(nums[i]) ; 
        } return false;
    }  
};
class Solution242 {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int > m;
        if (s.size() != t.size()){
            return false ;
        }
        for ( char x: s){
            m[x]++ ;
        }
        for (char x: t){
            m[x]-- ;
        }
        for (auto& pair : m){
            if (pair.second != 0){
                return false ;
            } 
        }
        return true ;
    }
};
int main() {
    std::vector <int> arr ;
    int q ;
    int n ;
    std::cout << "\nhow many elements = " ;
    std::cin >> q ;
    for ( int i = 0 ; i < q ; ++i ) {
        std::cout << "\n" << i+1 << " enter array " ;
        std::cin >> n ;
        arr.push_back(n) ;
    }
    int r ;
    std::cout << "\nenter target= ";
    std::cin >> r ;
    for ( int w = 0 ; w < (int)arr.size() ; w++ ) {
        for ( int e =0 ; e < (int)arr.size() ; e++ ) {
            if (arr[w] + arr[e] == r ) {
                std::cout << "\n[" << w << "," << e << "]" ;
            }
        }
    }
    return 0 ;
}