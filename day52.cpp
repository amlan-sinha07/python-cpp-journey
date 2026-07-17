#include <iostream>
#include <vector>
using namespace std;
class Solution207 {
public:
    bool dfs(int course,vector<vector<int>>& adj,vector<int>& state){
        if (state[course]==1){return false;}
        if (state[course]==2){return true;}
        state[course]=1;
        for (int prereq:adj[course]){
            if (dfs(prereq,adj,state)==false) return false;
        }
        state[course]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    vector<int>state(numCourses,0);
    for (auto& p:prerequisites){
        adj[p[0]].push_back(p[1]);
    }
    for (int i=0;i<numCourses;++i){
        if (dfs(i,adj,state)==false) return false;
    }
    return true;
    }
};
class Solution200 {
public:
    void dfs(int row,int column,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        if (row<0 || row>=grid.size() || column<0 || column>=grid[0].size()) return ;
        if (visited[row][column] || grid[row][column]=='0') return ;
        visited[row][column]=true;
        int dr[]={1,-1,0,0}; // {down,up,left,right}
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;++i){
            dfs(row+dr[i],column+dc[i],grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int column=grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(column,false));
        int count=0;
        for (int r=0;r<row;++r){
            for (int c=0;c<column;++c){
                if (grid[r][c]=='1' && !visited[r][c]){
                    dfs(r,c,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};