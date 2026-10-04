class Solution {
public:
    int countAtMost(vector<int>& nums, int limit) {
        if (limit <= 0)
            return 0;

        unordered_map<int, int> frequency;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            frequency[nums[right]]++;

            while (frequency.size() > limit) {
                int value = nums[left];

                frequency[value]--;

                if (frequency[value] == 0) {
                    frequency.erase(value);
                }

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k <= 0)
            return 0;

        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};