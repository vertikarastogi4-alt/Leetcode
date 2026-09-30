class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> number;
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            number.push_back(i);
        }
        number.push_back(n);
        string ans = "";
        k = k - 1;
        while (true) {
            int index = k / fact;
            ans += to_string(number[index]);
            number.erase(number.begin() + index);
            if (number.size() == 0)
                break;
            k = k % fact;
            fact = fact / number.size();
        }
        return ans;
    }
};