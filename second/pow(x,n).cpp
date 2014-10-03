class Solution {
public:
    double pow(double x, int n) {
        map<int,double> dp = {{0, 1.0}, {1, x}};
        bool positive = true;
        unsigned num;
        if (n<0) {
            positive = false;
            num = -n;
        } else {
            num = n;
        }
        unsigned int p = 1;
        while (p < num) {
            p *= 2;
            dp[p] = dp[p/2]*dp[p/2];
        }
        double result = 1.0;
        if (p > num) {
            p /= 2;
        }
        while (num>0) {
            if (num >= p) {
                result *= dp[p];
                num -= p;
            }
            p /= 2;
        }
        return positive?result:1/result;
    }
};

class Solution {
public:
    double pow(double x, int n) {
        if (n>0) return pow(1/x, -n);
        double result = 1.0;
        while (n>0) {
            if (n&1) {
                result *= x;
            }
            n /= 2;
            x *= x;
        }
        return 1/result;
    }
};