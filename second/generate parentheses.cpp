class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string result;
        vector<string> results;
        generateParenthesisRecur(n, 0, 0, result, results);
        return results;
    }

private:
    void generateParenthesisRecur(int n, int left, int right, string &result,
                                  vector<string> &results) {
        if (result.size() == n*2) {
            results.push_back(result);
        } else {
            if (left < n) {
                result.push_back('(');
                generateParenthesisRecur(n, left+1, right, result, results);
                result.pop_back();
            }
            if (left > right) {
                result.push_back(')');
                generateParenthesisRecur(n, left, right+1, result, results);
                result.pop_back();
            }
        }
    }
};