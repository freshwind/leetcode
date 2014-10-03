class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2) return;
        int i = int(num.size())-2;
        for (; i >= 0 && num[i] > num[i+1]; --i);
        if (i >= 0) {
            int j = int(num.size())-1;
            for (; num[i] >= num[j]; --j);
            swap(num[i], num[j]);
        }
        i++;
        int j = int(num.size())-1;
        while (i < j) {
            swap(num[i++], num[j--]);
        }
    }
};
