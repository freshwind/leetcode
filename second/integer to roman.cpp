#include "stdlib.h"

class Solution {
public:
    string intToRoman(int num) {
        string result;
        while (num > 0) {
            if (num >= 1000) {
                result.push_back('M');
                num -= 1000;
            } else if (num >= 900) {
                result = result + "DM";
                num -= 900;
            } else if (num >= 500) {
                result.push_back('D');
                num -= 500;
            } else if (num >= 400) {
                result = result + "CD";
                num -= 400;
            } else if (num >= 100) {
                result.push_back('C');
                num -= 100;
            } else if (num >= 90) {
                result = result + "XC";
                num -= 90;
            } else if (num >= 50) {
                result.push_back('L');
                num -= 50;
            } else if (num >= 40) {
                result += "XL";
                num -= 40;
            } else if (num >= 10) {
                result.push_back('L');
                num -= 10;
            } else if (num >= 9) {
                result += "IX";
                num -= 9;
            } else if (num >= 5) {
                result.push_back('V');
                num -= 5;
            } else if (num >= 4) {
                result += "IV";
                num -= 4;
            } else if (num >= 1) {
                result.push_back('I');
                num --;
            }
        }
        return result;
    }

    string intToRoman(int num) {
        const int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int count;
        string result;
        for (int i = 0; num > 0; ++i) {
            count = num / numbers[i];
            num = num % numbers[i];
            for (int j = 0; j < count; ++j) {
                result = result + symbols[i];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout <<sol.intToRoman(13);
}