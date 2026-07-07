#include <iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution572 {
public:
    bool issametree(TreeNode* root,TreeNode* subRoot){
        if (root==nullptr && subRoot==nullptr){
            return true;
        }
        if (root==nullptr || subRoot==nullptr){
            return false;
        }
        if (root!=nullptr && subRoot!=nullptr && root->val==subRoot->val){
            return (issametree(root->left,subRoot->left) && issametree(root->right,subRoot->right));
        }
        if (root!=nullptr && subRoot!=nullptr && root->val!=subRoot->val){
            return false;
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr){
            return false;
        }
        if (issametree(root,subRoot)){
            return true;
        } 
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};