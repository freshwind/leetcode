class Solution {
private:
    map<int,double> powResult;
public:
    double pow(double x, int n) {
        int positiveFlag = 0;
        if (n == 0 || x == 1.0) {
            return 1.0;
        }
        if (x == -1.0) {
            return n%2 ? -1.0: 1.0;
        }
        if (n < 1) {
            positiveFlag = 1;
        }
        powResult.insert( pair<int, double>(1, x));
        powResult.insert( pair<int, double>(2, x*x));
        if (positiveFlag == 1) {
            n = -n;
            return 1/powRecur(x,n);
        } else {
            return powRecur(x, n);
        }
    }

    double powRecur(double x, int n) {
        if (powResult.find(n)!=powResult.end()) {
            return powResult.find(n)->second;
        } else {
            if (n%2) {
                double result = powRecur(x, n/2) * powRecur(x, n/2) * x;
                powResult.insert( pair<int, double>(n, result));
                return result;
            } else {
                double result = powRecur(x, n/2) * powRecur(x, n/2);
                powResult.insert( pair<int, double>(n, result));
                return result;
            }
        }
    }
};