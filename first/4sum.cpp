class Solution {
public:
    void fourSumRecur(unordered_set<int> &hashmap,
                      vector<vector<int> > &results,
                      vector<int> result,
                      vector<int> &unique_nums,
                      vector<int> &appear_times,
                      int sum, int current, int target) {
        int max;
        int min;
        if (current == unique_nums.size()) return;
        // print(result);
        int current_len = result.size();
        if (current_len == 3) {
            unordered_set<int>::const_iterator got = hashmap.find(target-sum);
            if (got != hashmap.end() && target-sum != result.back()) {
                result.push_back(target-sum);
                results.push_back(result);
            }
        } else {
            fourSumRecur(hashmap, results, result, unique_nums,
                                     appear_times, sum,
                                     current+1, target);
            for(int i = 0; i < appear_times[current] && i < 4-current_len;++i){
                result.push_back(unique_nums[current]);
                sum += unique_nums[current];
                // current++;
                if (result.size() != 4) {
                    max = sum + (4-result.size())*unique_nums.back();
                    min = sum + (4-result.size())*unique_nums[current];
                    if (target <= max && target >= min) {
                        fourSumRecur(hashmap, results, result, unique_nums,
                                     appear_times, sum,
                                     current+1, target);
                    }
                } else if (sum == target) {
                    results.push_back(result);
                }
            }
        }
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int> >();
        sort(num.begin(), num.end());
        int index = num.size()-1;
        int max = num[index] + num[index-1] + num[index-2] + num[index-3];
        if (target > max) return vector<vector<int> >();
        int min = num[0] + num[1] + num[2] + num[3];
        if (target < min) return vector<vector<int> >();
        vector<int> unique_num;
        vector<int> appear_times;
        unique_num.push_back(num[0]);
        appear_times.push_back(1);
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == unique_num.back()) {
                appear_times.back()++;
            } else {
                unique_num.push_back(num[i]);
                appear_times.push_back(1);
            }
        }
        unordered_set<int> hashmap(unique_num.begin(), unique_num.end());
        vector<vector<int> > results;
        vector<int> result;
        // print(unique_num);
        // print(appear_times);
        fourSumRecur(hashmap, results, result, unique_num,
                     appear_times, 0, 0, target);
        return results;
    }
};