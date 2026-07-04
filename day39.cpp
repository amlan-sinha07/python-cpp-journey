#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    ListNode *next;
};
class Solution104 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};
class Solution226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return nullptr;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
struct ListNode {
    int val;
    ListNode *next;
};
class SolutionMockInterview{
public:
    bool hasCycle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        if (head == nullptr){
            return false;
        }
        while (fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                return true;
            }
        } return false;
    }
};
class Solution242 {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>seen;
        if (s.size()!=t.size()){
            return false;
        }
        for (char x:s){
            seen[x]++;
        }
        for (char x:t){
            seen[x]--;
        }
        for (auto& pair:seen){
            if (pair.second !=0){
                return false;
            }
        }
        return true;
    }
};
class Solution169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>seen;
        if (!nums.empty()){
            for (int x:nums){
                seen[x]++;
            }
            for (auto& pair:seen){
                if (pair.second>((int)nums.size()/2)){
                    return pair.first;
                }
            }
        } return 0;
    } 
};