class Solution {
public:
    long long largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> indices;
        long long maxArea = 0;
 
        for (int index = 0; index <= n; index++) {
            int currentHeight = index == n ? 0 : heights[index];
             while (!indices.empty() &&
                   heights[indices.top()] >= currentHeight) {
                int height = heights[indices.top()];
                indices.pop();
                 int width = indices.empty()
                    ? index
                    : index - indices.top() - 1;
                long long area = 1LL * height * width;
                maxArea = max(maxArea, area);
                   }
            if (index < n) {
                indices.push(index);
            }
        }
        return maxArea;
    }
};