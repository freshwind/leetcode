class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string result;
        letterCombinationsRecur(results, result, digits, 0);
        return results;
    }

    void letterCombinationsRecur(vector<string> &results, string &result, string digits, int pos) {
        if (pos == digits.size()) {
            results.push_back(result);
            return;
        }
        if (digits[pos] == '9') {
            for (int i = 0; i != 4; ++i) {
                result.push_back('w'+i);
                letterCombinationsRecur(results, result, digits, pos+1);
                result.pop_back();
            }
        } else if (digits[pos] == '7') {
            for (int i = 0; i != 4; ++i) {
                result.push_back('p'+i);
                letterCombinationsRecur(results, result, digits, pos+1);
                result.pop_back();
            }
        } else if (digits[pos] == '8') {
            for (int i = 0; i != 3; ++i) {
                result.push_back('t'+i);
                letterCombinationsRecur(results, result, digits, pos+1);
                result.pop_back();
            }
        } else {
            char start = 'a' + 3*(digits[pos]-'2');
            for (int i = 0; i != 3; ++i) {
                result.push_back(start+i);
                letterCombinationsRecur(results, result, digits, pos+1);
                result.pop_back();
            }
        }
    }
};