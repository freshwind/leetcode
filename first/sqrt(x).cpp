class Solution {
public:
    int sqrt(int x) {
        if (x <  2) return x;
        int start = 0; //if start =1, may overflow
        int end = x;
        int mid;
        while (start != end-1) {
            mid = (start + end)/2;
            if (mid == x/mid) return mid;
            else mid < x/mid ? start = mid : end = mid;
        }
        return start;
    }
};