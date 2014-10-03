class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > results;
        vector<int> result;
        dfs(root, sum, 0, result, results);
        return results;
    }

private:
    void dfs(TreeNode *root, int sum, int curr, vector<int> &result, vector<vector<int> > &results) {
        if (!root) return;
        result.push_back(root->val);
        curr += root->val;
        if (!root->left && !root->right && sum == curr) {
            results.push_back(result);
        } else {
            dfs(root->left, sum, curr, result, results);
            dfs(root->right, sum, curr, result, results);
        }
        result.pop_back();
    }
};
