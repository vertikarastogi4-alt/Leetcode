class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> frq;

        for (char ch : s) {
            frq[ch]++;
        }
        for (char ch : t) {
            frq[ch]--;

            if (frq[ch] < 0)
                return false;
        }

        return true;
    }
};
   

