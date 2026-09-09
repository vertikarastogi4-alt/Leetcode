class Solution {
public:
    int countCommas(int n) {
     return n < 1000 ? 0 : (n - 999) + (n >= 1000000 ? n - 999999 : 0) + (n >= 1000000000 ? n - 999999999 : 0); 
    }
};