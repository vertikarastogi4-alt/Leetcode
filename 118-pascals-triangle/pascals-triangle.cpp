class Solution {
public:
    vector<vector<int>> generate(int numRows) {
  
        vector<vector<int>> triangle;
 
      
        for (int row = 0; row < numRows; row++) {
            vector<int> current(row + 1, 1);
 
            for (int col = 1; col < row; col++) {
                current[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
 
            triangle.push_back(current);
        }
 
        return triangle;   
    }
};