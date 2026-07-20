//
//
#include <iostream>
#include <unordered_set>
using namespace std;

class solution3 {
    int length_of_longest_substring(string s){
        unordered_set<char>window;

        int left=0;
        int ans=0;
        for (int right=0;right<s.size();++right){

            while (window.count(s[right])){
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
class solution5 {
    public:
    int expand(string &s,int left,int right){
        while(left>=0,right<s.size()){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longest_palindrome(string s){
        if (s.empty()){
            return "";
        }
        int start=0;
        int maxlen=1;
        for (int i=0;i<s.size();++i){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if (len>maxlen){
                start=i-(len-1)/2;
                maxlen=len;
            }
        } return s.substr(start,maxlen);
    }
};