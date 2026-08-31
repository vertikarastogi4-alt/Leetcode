class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;

        while (curr->next != NULL) {

       
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (first == -1) {
        
                    first = pos;
                }
                else {
 
                    minDist = min(minDist, pos - last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (first == -1 || first == last)
            return ans;

        ans[0] = minDist;
        ans[1] = last - first;

        return ans;
    }
};