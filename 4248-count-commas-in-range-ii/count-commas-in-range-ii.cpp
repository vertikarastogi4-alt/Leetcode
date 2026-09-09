class Solution {
public:
    long long countCommas(long long n) {
       long long ans = 0;
        
        for (long long x = 1000, commas = 1; x <= n; x *= 1000, commas++) {
            ans += (n - x + 1);
        }
        
        return ans;  
    }
};