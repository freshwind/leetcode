class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size()<2) return;
        int start;
        int end = num.size()-1;
        int probe = num.size()-2;
        for (; probe >= 0 && num[probe] >= num[probe+1]; --probe) {
        }
        if (probe == num.size()-2) {
            start = probe;
        } else if (probe == -1) {
            start = 0;
        } else {
            int swap_index = probe+1;
            for(; swap_index <= num.size()-1 && num[swap_index]>num[probe];
                ++swap_index){
            }
            swap_index--;
            swap(num[probe], num[swap_index]);
            start = probe+1;
        }
        while (start < end) {
            swap(num[start], num[end]);
            start++;
            end--;
        }
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

};