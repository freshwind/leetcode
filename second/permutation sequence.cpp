class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> factorial(n, 1);
        string result;
        string map;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i-1]*i;
            map.push_back('0'+i);
        }
        map.push_back('0'+n)
        for (int i = n-1; i >= 0; --i) {
            result.push_back(map[k/factorial[i]]);
            map.erase(map.begin()+int(k/factorial[i]));
            k %= factorial[i];
        }
        return result;
    }
};
