#include <iostream>
#include <unordered_map>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution112 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr){
            return false;
        }
        int remainingSum=targetSum-root->val;
        if (root->left==nullptr && root->right==nullptr && remainingSum==0){
            return true;
        }
        return (hasPathSum(root->left,remainingSum) || hasPathSum(root->right,remainingSum));
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution617 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==nullptr && root2==nullptr){
            return nullptr;
        }
        if (root1==nullptr){return root2;}
        if (root2==nullptr){return root1;}
        TreeNode* merge=new TreeNode(root1->val+root2->val);
        merge->left=mergeTrees(root1->left,root2->left);
        merge->right=mergeTrees(root1->right,root2->right);
        return merge;
    }
};
class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>seen;
        for(char x:ransomNote){seen[x]++;}
        for(char x:magazine){seen[x]--;}
        for(auto& pair:seen){if(pair.second>0){return false;}}
        return true;
    }
};
class Solution136 {
public:
    int singleNumber(vector<int>& nums) {
        int accumulate=0;
        for(int i=0;i<(int)nums.size();++i){
            accumulate^=nums[i];
        }
        return accumulate;
    } 
};