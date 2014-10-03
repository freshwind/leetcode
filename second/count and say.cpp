class Solution {
private:
    string int2string(int n) {
        stringstream ss;
        ss <<n;
        return ss.str();
    }
public:
    string countAndSay(int n) {
        string result = "1";
        string temp;
        for (int i = 1; i < n; ++i) {
            char curr = result[0];
            int times = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == curr) {
                    times++;
                } else {
                    temp += (int2string(times)+curr);
                    curr = result[j];
                    times = 1;
                }
            }
            temp += (int2string(times)+curr);
            result = temp;
            temp.clear();
        }
        return result;
    }
};
