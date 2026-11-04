class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int  XOR = 0;
        int n = nums.size();
        for( int i =0 ; i < n ; i++){
            XOR = XOR^nums[i];
        }
        return XOR;
    }
};