class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        k = k % len;
                if (k == 0) return head;

        tail->next = head;

        ListNode* newLastNode = head;
        for (int i = 1; i < len - k; i++) {
            newLastNode = newLastNode->next;
        }

        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        return newHead;
    }
};