class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
        vector<int> answer(n, -1);
        stack<int> candidates;
 
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
             while (!candidates.empty() &&
                   candidates.top() <= nums[index]) {
                candidates.pop();
            }
            if (i < n && !candidates.empty()) {
                answer[index] = candidates.top();
            }
 
            candidates.push(nums[index]);
        }
 
        return answer;  
    }
};