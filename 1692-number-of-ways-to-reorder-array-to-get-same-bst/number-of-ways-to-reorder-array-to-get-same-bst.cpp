class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> combinations;
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        combinations.assign(n + 1, vector<long long>(n + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            combinations[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
            }
        }
        
        return (getWays(nums) - 1 + MOD) % MOD;
    }
    
private:
    long long getWays(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        
        int root = nums[0];
        vector<int> left, right;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long leftWays = getWays(left);
        long long rightWays = getWays(right);
        long long ways = combinations[left.size() + right.size()][left.size()];
        
        return (((ways * leftWays) % MOD) * rightWays) % MOD;
    }
};