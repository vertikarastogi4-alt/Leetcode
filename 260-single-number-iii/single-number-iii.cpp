class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         unordered_map<int, int> frequency;
 
        for (int num : nums) {
            frequency[num]++;
        }
 
        vector<int> answer;
 
        for (auto& entry : frequency) {
            if (entry.second == 1) {
                answer.push_back(entry.first);
            }
        }
 
        return answer;
  
    }
};