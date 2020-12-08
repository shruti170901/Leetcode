// https://leetcode.com/problems/merge-k-sorted-lists/

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int i, n=v.size(), idx, mn;
        ListNode* root=new ListNode;
        ListNode* temp=root;
        while(true){
            mn=INT_MAX;
            for(i=0;i<n;i++){
                if(v[i]!=NULL && v[i]->val<mn){
                    mn=v[i]->val;
                    idx=i;
                }
            }
            if(mn==INT_MAX) break;
            temp->next=v[idx];
            temp=temp->next;
            v[idx]=v[idx]->next;
        }
        return root->next;
    }
};