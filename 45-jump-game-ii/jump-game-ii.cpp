class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& memo) {
        int n = nums.size();

        if (index >= n - 1)
            return 0;

        if (memo[index] != -1)
            return memo[index];

        int minJumps = INT_MAX;
        int farthestJump = min(n - 1, index + nums[index]);

        for (int nextIndex = index + 1; nextIndex <= farthestJump; nextIndex++) {
            int nextJumps = solve(nextIndex, nums, memo);

            if (nextJumps != INT_MAX) {
                minJumps = min(minJumps, 1 + nextJumps);
            }
        }
        return memo[index] = minJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);

        return solve(0, nums, memo);
    }
};