class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string result;
        for (int i = 0; i < nRows; ++i) {
            int last = -1;
            int current;
            for (int j = 0; j < s.size()+nRows; j+=(2*nRows-2)) {
                current = j-i;
                if (current>=0 && current < s.size() && current != last) {
                    result.push_back(s[current]);
                    last = current;
                }
                current = j+i;
                if (current>=0 && current < s.size() && current != last) {
                    result.push_back(s[current]);
                    last = current;
                }
            }
        }
        return result;
    }
};
