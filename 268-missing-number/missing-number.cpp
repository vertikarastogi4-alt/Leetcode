class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> present(nums.size() + 1, false);
         for (int value : nums) {
            present[value] = true;
        }
         for (int value = 0; value <= nums.size(); value++) {
            if (!present[value]) {
                return value;
            }
        }
 
        return -1;   
    }
};