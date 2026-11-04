class Solution {
public:
    int singleNumber(vector<int>& nums) {
          unordered_map<int, int> frequency;
                for (int num : nums) {
            frequency[num]++;
        }
                for (auto pair : frequency) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1; 
    }
};
