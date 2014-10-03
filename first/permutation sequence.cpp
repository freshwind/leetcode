class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        vector<int> factorial(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i-1]*i;
            nums.push_back(i+'0');
        }
        string result;
        int insert_index;
        k = k-1;
        for (int i = 1; i < n; ++i) {
            insert_index = k / factorial[n-i];
            result.push_back(nums[insert_index]);
            nums.erase(nums.begin()+insert_index);
            k = k % factorial[n-i];
        }
        result.push_back(nums[0]);
        return result;
    }
};