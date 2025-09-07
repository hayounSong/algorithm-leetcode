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

ListNode* sample2=new ListNode(0);
ListNode* mergeTwo(ListNode* a,ListNode* b){
    ListNode* value=sample2;
    ListNode* cur=value;
    while(a!=nullptr&&b!=nullptr){
        if(a->val<=b->val){
            cur->next=a;
            cur=cur->next;
            a=a->next;
            }
            else{
            cur->next=b;
            cur=cur->next;
                b=b->next;
            }
        }
    cur->next=a?a:b;
    return value->next;
} 
ListNode* divide(vector<ListNode*>& lists, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return lists[l];
    int mid = (l + r) / 2;
    ListNode* left = divide(lists, l, mid);
    ListNode* right = divide(lists, mid + 1, r);
    return mergeTwo(left, right);
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return nullptr;
        return divide(lists,0,len-1);
    }
};