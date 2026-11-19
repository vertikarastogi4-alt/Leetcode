class Solution {
    private:
    int findHeight(
        TreeNode* node,
        int& diameter ) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight =  findHeight(node->left, diameter);
        int rightHeight = findHeight(node->right, diameter);
        diameter = max( diameter, leftHeight + rightHeight);
          return 1 + max(leftHeight, rightHeight);
    }
 
public:

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
         findHeight(root, diameter); 
        return diameter;
    }
};
