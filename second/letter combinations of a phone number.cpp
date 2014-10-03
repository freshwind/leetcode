class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string result;
        letterCombinationsRecur(digits, 0, results, result);
        return results;
    }

    void letterCombinationsRecur(string digits, int curr, vector<string> &results, string &result) {
        if (curr == digits.size()) {
            results.push_back(result);
        } else {
            const static vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            int index = digits[curr]-'2';
            for (int i = 0; i < map[index].size(); ++i) {
                result.push_back(map[index][i]);
                letterCombinationsRecur(digits, curr+1, results, result);
                result.pop_back();
            }
        }
    }
};
