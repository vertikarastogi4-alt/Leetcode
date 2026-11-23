
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int column = current.second.first;
            int row = current.second.second;

            nodes[column][row].insert(node->val);

            if (node->left != nullptr) {
                q.push({node->left, {column - 1, row + 1}});
            }

            if (node->right != nullptr) {
                q.push({node->right, {column + 1, row + 1}});
            }
        }

        vector<vector<int>> answer;

        for (auto& columnEntry : nodes) {
            vector<int> columnValues;

            for (auto& rowEntry : columnEntry.second) {
                for (int value : rowEntry.second) {
                    columnValues.push_back(value);
                }
            }
            answer.push_back(columnValues);
        }
        return answer;
    }
};
