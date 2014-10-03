#include <list>
#include "stdlib.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        list<int> list_num(num.begin(), num.end());
        vector<vector<int> > results;
        vector<int> result;
        // print(results);
        permuteRecur(list_num, results, result);
        return results;
    }
    void permuteRecur(list<int> num, vector<vector<int> > &results,
                      vector<int> &result) {
        // print(results);
        if (num.size() == 1) {
            result.push_back(num.back());
            results.push_back(result);
            result.pop_back();
        } else {
            // print(num);
            list<int>::iterator it = num.begin();
            int temp;
            while (it != num.end()) {
                temp = *it;
                // cout <<*temp <<endl;
                result.push_back(temp);
                it = num.erase(it);
                permuteRecur(num, results, result);
                num.emplace(it, temp);
                result.pop_back();
            }
        }
    }
};

int main() {
    vector<int> num = {0, 1, 2};
    Solution sol;
    print(sol.permute(num));
    // vector<int> num = {0};
    // list<int> l = {num.begin(), num.end()};
    // list<int>::iterator it = l.begin();
    // print(it != l.end());
    // int temp = *it;
    // cout <<*it <<endl;
    // it = l.erase(it);
    // l.insert(it, temp);
    // print(l);
    // cout <<*it <<endl;
    // print(it != l.end());
}