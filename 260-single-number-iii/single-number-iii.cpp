class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        uint32_t bits = static_cast<uint32_t>(xorResult);
        uint32_t mask = bits & (~bits + 1u);
 
        int group1 = 0;
        int group2 = 0;
        for (int num : nums) {
            if ((static_cast<uint32_t>(num) & mask) != 0) {
                group1 ^= num;
            } else {
                group2 ^= num;
            }
        }
 
        return {group1, group2};
  
    }
};