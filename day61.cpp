//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
//lc=42 trapping rain water
//height=[0,1,0,2,1,0,1,3,2,1,2,1]
//output = 6 
int trap(vector<int>& height){
    int left=0;
    int right=height.size()-1;

    int left_max=0;
    int right_max=0;

    int total_water =0 ;

    while ( left< right ){
        if ( height[left] < height[right]){
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                total_water += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max=height[right];
            } else {
                total_water+=right_max-height[right];
            }
            right--;
        }
    }
    return total_water;
}
// 2. LeetCode #1762 - Buildings with Ocean View 
// input = [4,2,3,1]
// output = [0,2,3]
//
vector<int>findBuildings(vector<int>& heights){
    vector<int>ans;

    int mx=0;
    for (int i=heights.size()-1;i>=0;--i){

        if(heights[i]>mx){
            ans.push_back(i);

            mx=heights[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//leetcode = 84 largest rectangle in histogram
// height= [2,1,5,6,3,2]
// output = 10
int largestRectangleArea(vector<int>& heights){
    stack<int>st;

    int ans=0;
    heights.push_back(0);

    for (int i=0;i<heights.size();++i){
        while(!st.empty() &&
            heights[st.top()]>heights[i]){

                int h=heights[st.top()];
                st.pop();
                int left=st.empty() ? -1:st.top();

                int width=i-left-1;
                ans=max(ans,h*width);
            }
            st.push(i);
    } return ans;
}