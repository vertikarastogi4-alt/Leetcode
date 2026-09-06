class Solution {
public:

    string longestPalindrome(string str) {

        string LPS = string(1, str[0]);
        int n = str.size();

        int low, high;

        for (int i = 1; i < n; i++) {

            low = i;
            high = i;

            while (low >= 0 && high < n && str[low] == str[high]) {
                low--;
                high++;
            }

            string palindrome = str.substr(low + 1, high - low - 1);

            if (palindrome.size() > LPS.size()) {
                LPS = palindrome;
            }

            low = i - 1;
            high = i;

            while (low >= 0 && high < n && str[low] == str[high]) {
                low--;
                high++;
            }

            palindrome = str.substr(low + 1, high - low - 1);

            if (palindrome.size() > LPS.size()) {
                LPS = palindrome;
            }
        }

        return LPS;
    }
};