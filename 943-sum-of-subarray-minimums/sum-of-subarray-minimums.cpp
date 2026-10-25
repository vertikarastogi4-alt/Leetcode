class Solution {
private:
    vector<int> findPreviousLess(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> indices;
 
        for (int i = 0; i < n; i++) {
            while (!indices.empty() &&
                   arr[indices.top()] >= arr[i]) {
                indices.pop();
            }
 
            if (!indices.empty()) {
                previousLess[i] = indices.top();
            }
 
            indices.push(i);
        }
 
        return previousLess;
    }
 vector<int> findNextLessOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> indices;
 
        for (int i = n - 1; i >= 0; i--) {
            while (!indices.empty() &&
                   arr[indices.top()] > arr[i]) {
                indices.pop();
            }
             if (!indices.empty()) {
                nextLessOrEqual[i] = indices.top();
            }
 
            indices.push(i);
        }
 
        return nextLessOrEqual;
    }


public:
    int sumSubarrayMins(vector<int>& arr) {
 int n = arr.size();
        long long mod = 1000000007;
 
        vector<int> previousLess = findPreviousLess(arr);
        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);
 
        long long answer = 0;
 
        for (int i = 0; i < n; i++) {
            long long leftChoices = i - previousLess[i];
            long long rightChoices = nextLessOrEqual[i] - i;
 
            long long contribution =
                (arr[i] * leftChoices) % mod;
            contribution =
                (contribution * rightChoices) % mod;
 
            answer = (answer + contribution) % mod;
        }
 
        return (int)answer;
    }
};