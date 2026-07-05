class Solution110 {
public:
    int maxHeight(TreeNode* root){
        if (root==nullptr){
            return 0;
        }
        return 1+max(maxHeight(root->left),maxHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {

        if (root==nullptr){
            return true;
        }
        int leftheight=maxHeight(root->left);
        int rightheight=maxHeight(root->right);
        if (abs(leftheight-rightheight)>1){
            return false;
        } return (isBalanced(root->left) && isBalanced(root->right));
    }
};
class Solution100 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr){
            return true;
        }
        if (p!=nullptr && q==nullptr || p==nullptr && q!=nullptr){
            return false;
        }
        if (p!=nullptr && q!= nullptr && p->val != q->val){
            return false;
        }
        if (p!=nullptr && q!=nullptr && p->val == q->val){
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        } return true;
    }
};
class Solution101 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr){
            return true;
        } return (isMirror(root->right,root->left));        
    }
    bool isMirror(TreeNode* p,TreeNode* q){
        if (p==nullptr && q==nullptr){
            return true;
        }
        if (p!=nullptr &&q==nullptr || p==nullptr&& q!=nullptr){
            return false;
        }
        if (p!=nullptr && q!=nullptr && p->val!=q->val){
            return false;
        }
        if (p!=nullptr && q!=nullptr && p->val==q->val){
            return (isMirror(p->left,q->right) && isMirror(p->right,q->left));
        } return true;
    }
};