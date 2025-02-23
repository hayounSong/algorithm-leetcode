
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *v1 = l1;
        ListNode *v2 = l2;
        int current = 0;
        ListNode *start = new ListNode();
        ListNode *curnode = start;
        while (v1 || v2 || (current > 0))
        {
            int sum = current;
            if (v1)
            {
                sum = sum + v1->val;
                v1 = v1->next;
            }
            if (v2)
            {
                sum = sum + v2->val;
                v2 = v2->next;
            }
            ListNode *a = new ListNode(sum % 10);
            curnode->next = a;
            curnode = a;
            current = sum / 10;
        }
        return start->next;
    }
};