//lc=22
#include <iostream>
#include <vector>
using namespace std;
class solution22{
    public:
    void backtrack(string &path,
                vector<string>&result,
                const int open,
                const int close,
                const int n){
        if ((int)path.size()==2*n){
            result.push_back(path);
            return ;
        }
        if (open<n){
            path.push_back('(');
            backtrack(path,result,open+1,close,n);
            path.pop_back();
        }
        if (close<open){
            path.push_back(')');
            backtrack(path,result,open,close+1,n);
            path.pop_back();
        }
                }
    vector<string>generateparenthesis(int n){
        vector<string>result;
        string path="";
        backtrack(path,result,0,0,n);
        return result;
    }
};
//lc=77
class solution77{
public:
void backtrack(vector<int>&path,vector<vector<int>>&result,int n,int k,int start){
    if (path.size()==k){
        result.push_back(path);
        return;
    }
    for (int i=start;i<=n;++i){
        path.push_back(i);
        backtrack(path,result,n,k,i+1);
        path.pop_back();
    }
}
vector<vector<int>>combine(int k,int n){
    vector<vector<int>>result;
    vector<int>path;
    backtrack(path,result,n,k,1);
    return result;
}
};