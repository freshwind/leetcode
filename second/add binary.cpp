class Solution {
public:
    string addBinary(string a, string b) {
        string result(max(a.size(), b.size()), '0');
        int carry = 0;
        int curr = result.size()-1;
        while (!a.empty() && !b.empty()) {
            int temp = a.back() + b.back() + carry - '0' - '0';
            if (temp == 3) {
                result[curr] = '1';
                carry = 1;
            } else if (temp == 2) {
                result[curr] = '0';
                carry = 1;
            } else {
                result[curr] = temp+'0';
                carry = 0;
            }
            a.pop_back();
            b.pop_back();
            curr--;
        }
        string remaining;
        if (a.empty()) {
            remaining = b;
        } else {
            remaining = a;
        }
        while (!remaining.empty()) {
            int temp = remaining.back()+carry - '0';
            if (temp == 2) {
                result[curr] = '0';
                carry = 1;
            } else {
                result[curr] = temp + '0';
                carry = 0;
            }
            remaining.pop_back();
            curr--;
        }
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string c(max(a.size(), b.size()), '0');
        int i = a.size()-1;
        int j = b.size()-1;
        int t = c.size()-1;
        int carry = 0;
        for (;i>=0||j>=0; --i, --j, --t) {
            int av = i>=0? a[i]-'0':0;
            int bv = j>=0? b[j]-'0':0;
            int sum = av+bv+carry;
            carry = sum/2;
            c[t] += sum&1;
        }
        if (carry)
            c.insert(c.begin(), '1');
        return c;
    }
};