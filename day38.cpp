#include <iostream>
#include <vector>
#include <ListNode>
#include <unordered_map>
using namespace std;
class Solution344 {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right =s.size()-1;
        while (right>left){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;
        while (curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        } return prev;
    }
};
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (list1!=NULL && list2!=NULL){
        if (list1->val <=list2->val){
            tail->next=list1;
            list1=list1->next;
        }
        else {
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
    }
    if (list1!=NULL) tail->next=list1;
    if (list2!=NULL) tail->next=list2;
        return dummy->next;
    }
};
class solution1 {
    public :
    vector<int> twosum(vector<int>& nums, int target){
        unordered_map<int,int>seen;
        for (int i=0;i<(int)nums.size();++i){
            int complement=target-seen[i];
            if (seen.count(complement)){
                return {seen[complement],i};
            } seen[nums[i]]=i;
        } return {};
    }
};
class Solution217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int i=0;i<(int)nums.size();++i){
            if (seen.count(nums[i])){
                return true;
            }
            seen.insert(nums[i]);
        } return false;
    }
};