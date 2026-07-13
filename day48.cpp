//lc=39
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
class solution39 {
    public:
    void backtrack(int index,vector<int>& candidates,vector<int>& path,vector<vector<int>>& result,int target) {
        if (target==0){
            result.push_back(path);
            return;
        }
        if (target<0 || index==(int)candidates.size()){
            return ;
        }
        for (int i=index;i<(int)candidates.size();++i){
            path.push_back(candidates[i]);
            backtrack(i,candidates,path,result,target-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>>combinationsum(vector<int>& candidates,int target){
        vector<vector<int>>result;
        vector<int>path;
        backtrack(0,candidates,path,result,target);
        return result;
    }
};