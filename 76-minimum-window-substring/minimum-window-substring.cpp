class Solution {
public:
    string minWindow(string s, string t) {
       int n = s.size();
        int m = t.size();
 
        if (n == 0 || m == 0 || n < m) {
            return "";
        }
 
        vector<int> need(128, 0);
        vector<int> window(128, 0);
 
        for (char ch : t) {
            need[(unsigned char)ch]++;
        }
 
        int left = 0;
        int matched = 0;
        int minLength = INT_MAX;
        int startIndex = -1;
 
        for (int right = 0; right < n; right++) {
            unsigned char current = s[right];
            window[current]++;
 
            if (
                need[current] > 0 &&
                window[current] <= need[current]
            ) {
                matched++;
            }
             while (matched == m) {
                int currentLength =
                    right - left + 1;
 
                if (currentLength < minLength) {
                    minLength = currentLength;
                    startIndex = left;
                }
 
                unsigned char leftChar = s[left];
                window[leftChar]--;
                 if (
                    need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]
                ) {
                    matched--;
                }
 
                left++;
            }
        }
         if (startIndex == -1) {
            return "";
        }
 
        return s.substr(startIndex, minLength);  
    }
};