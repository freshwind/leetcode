#include <vector>
#include <unordered_set>
#include "stdlib.h"
using namespace std;

// 1 1 1 1 2
// 4
// {1 1}
// {1 1}
// {1 2}
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > results;
        if (num.size() < 4) return results;
        sort(num.begin(), num.end());
        int search;
        int max;
        int len = num.size();
        unordered_set<int> hash(num.begin(), num.end());
        unordered_set<int>::const_iterator got;
        for (int i = 0; i < num.size()-3; ++i) {
            if (i && num[i] == num[i-1]) continue;
            max = num[i] + num[len-3] + num[len-2] + num[len-1];
            if (max < target) continue;
            for (int j = i+1; j < num.size()-2; ++j) {
                if (j != i+1 && num[j] == num[j-1]) continue;
                max = num[i] + num[j] + num[len-2] + num[len-1];
                if (max < target) continue;
                for (int s = j+1; s < num.size()-1; ++s) {
                    if (s != j+1 && num[s] == num[s-1]) continue;
                    max = num[i] + num[j] + num[s] + num[len-1];
                    if (max < target) continue;
                    search = target - num[i] - num[j] - num[s];
                    if (search == num[s+1]) {
                        results.push_back(vector<int>({num[i], num[j], num[s], num[s+1]}));
                        break;
                    } else if (search > num[s+1]) {
                        got = hash.find(search);
                        if (got != hash.end()) {
                            results.push_back(vector<int>({num[i], num[j], num[s], search}));
                            // break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        return results;
    }
};
// [1,0,-1,0,-2,2], 0
// Output: [[-2,-1,1,2]]
// Expected:   [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
class Solution {
    static bool myCmp(const vector<int>&l,const vector<int> &r) {
        return l[0] < r[0];
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<vector<int> > twoTuples;
        sort(num.begin() , num.end());
        int n = num.size();
        for (int i = 0 ; i < n ; i ++) {
            if (i && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i + 1 ; j < n ; j ++) {
                if (j != i + 1 && num[j] == num[j-1]) {
                    continue;
                }
                twoTuples.push_back({num[i]+num[j],i,j});
            }
        }
        sort(twoTuples.begin(), twoTuples.end() , myCmp);
        vector<int> tar(3,0);
        vector<vector<int>>::iterator lo , hi = twoTuples.end();
        for (int i = n - 1 ; i >= 0 ; i --) {
            if (i != n - 1 && num[i] == num[i+1]) {
                continue;
            }
            for (int j = i - 1 ; j >= 0 ; j --) {
                if (j != i - 1 && num[j] == num[j+1]) {
                    continue;
                }
                tar[0] = target - num[i] - num[j];
                lo = lower_bound(twoTuples.begin() , twoTuples.end() , tar , myCmp);
                hi = upper_bound(lo , twoTuples.end() , tar , myCmp);
                for (; lo != hi ; lo ++) {
                    if ((*lo)[2] < j) {
                        ret.push_back(vector<int>({num[(*lo)[1]] , num[(*lo)[2]] , num[j] , num[i]}));
                    }
                }
            }
        }
        return ret;
    }
};
/*
 O(n^3)版本 256ms
 */
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        sort(num.begin() , num.end());
        int n = num.size();
        for (int i = 0 ; i < n ; i ++) {
            if (i && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i + 1 ; j < n ; j ++) {
                if (j != i + 1 && num[j] == num[j-1]) {
                    continue;
                }
                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    int sum = num[i] + num[j] + num[lo] + num[hi];
                    if (target > sum) {
                        lo ++;
                    } else if (target == sum) {
                        ret.push_back({num[i] , num[j] , num[lo] , num[hi]});
                        do {
                            lo ++;
                        } while (lo < hi && num[lo] == num[lo-1]);
                        do {
                            hi --;
                        } while (lo < hi && num[hi] == num[hi+1]);
                    } else {
                        hi --;
                    }
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_multimap<int, {int int}> hash;
        int size = num.size();
        for (int i = 0; i < size-1; ++i) {
            for (int j = i+1; j < size; ++j) {
                hash.insert({num[i]+num[j], {i, j}});
            }
        }
        int x, a, b, c, d;
        vector<vector<int> > results;
        vector<int> result;
        for (auto it1 = hash.begin(); it1 != hash.end(); ++it1) {
            x = target - *it1;
            auto range = hash.equal_range(x);
            for (auto it2 = range.begin(); it2 != range.end(); ++it2) {
                a = it1->second.first;
                b = it1->second.second;
                c = it2->second.first;
                d = it2->second.second;
                if (a != c && a != d && b != c && b != d) {
                    result = {num[a], num[b], num[c], num[d]};
                    sort(result.begin(), result.end());
                    results.push_back(result);
                }
            }
        }
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), result.end());
        return results;
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > results;
        if (num.size() < 4) return results;
        sort(num.begin(), num.end());
        int N = num.size();
        unordered_multimap<int, {int, int}> hash;
        int appear_time;
        int fake_i;
        int current;
        for (int i = 0; i < N-1; i += appear_time) {
            appear_time = 1;
            fake_i = i;
            for (int j = i+1; j < N; ++j) {
                //1 1 1 1 , {2, 1, 2} {2, 3, 4} 4...
                //1 1 1, {2, 1, 2} 3 ...
                //1 1, {2, 1, 2} 1 ...
                //1 ..
                if (num[j] == num[i]) {
                    appear_time++;
                    if (appear_time == 2) {
                        hash.insert({2*num[i], {i, j}});
                    } else if (appear_time == 3) {
                        fake_i = j;
                    } else if (appear_time == 4) {
                        hash.insert({2*num[i], {j-1, j}});
                        fake_i = j;
                    }
                } else {
                    hash.insert(num[i]+num[j], {fake_i, j});
                }
            }
        }
        int search;
        for (auto i = hash.begin(); i != hash.end(); ++i) {
            search = target - i->first;
            auto range = hash.equal_range(search);
            for (auto j = range.begin(); )
        }
    }
};
int main() {
    Solution sol;
    vector<int> num = {1,0,-1,0,-2,2};
    print(sol.fourSum(num, 0));
    return 1;
}
