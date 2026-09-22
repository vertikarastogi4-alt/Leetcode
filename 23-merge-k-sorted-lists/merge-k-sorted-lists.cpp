class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
         return l2;
        if (l2 == NULL)
        return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    ListNode* solve(vector<ListNode*>& lists, int i) {
        if (i == lists.size())
            return NULL;

        return mergeTwoLists(lists[i], solve(lists, i + 1));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve(lists, 0);
    }
};