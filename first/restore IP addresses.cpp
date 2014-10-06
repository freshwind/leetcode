class Solution {
public:
    bool isValid(string &s, int begin, int end) {
        if ((end-begin) > 2 || (end-begin) < 0 ) return false;
        if (s[begin] == '0') {
            if (begin == end) return true;
            return false;
        }
        int value = 0;
        for (int i = begin; i <= end; ++i) {
            value = 10*value + s[i]-'0';
        }
        if (value <= 255 && value >=0) {
            return true;
        } else {
            return false;
        }
    }

    string constructIp(string &s, vector<int> &pos) {
        string temp = s;
        for (int i = 0; i < pos.size(); ++i) {
            temp.insert(temp.begin()+i+pos[i], '.');
        }
        return temp;
    }

    void restoreIpRecur(string &s, int last, vector<int> &pos, vector<string> &results) {
        if (pos.size() == 3) {
            if (isValid(s, last, s.size()-1)) {
                results.push_back(constructIp(s, pos));
            }
            return;
        }
        for (int i = last+1; i <= last+3 && i < s.size(); ++i) {
            if (isValid(s, last, i-1)) {
                pos.push_back(i);
                restoreIpRecur(s, i, pos, results);
                pos.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        vector<int> pos;
        restoreIpRecur(s, 0, pos, results);
        return results;
    }
};