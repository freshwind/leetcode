class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> result;
        vector<vector<int> > results;
        if (num.size() == 0) return results;

        //get sorted_num and num_time
        sort(num.begin(), num.end());
        vector<int> sorted_num;
        vector<int> num_time;
        sorted_num.push_back(num[0]);
        num_time.push_back(1);
        int current = 0;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == sorted_num[current]) {
                num_time[current]++;
            } else {
                sorted_num.push_back(num[i]);
                num_time.push_back(1);
                current++;
            }
        }

        //run recursion
        combinationSum2Recur(sorted_num, num_time, 0, target, result, results);

        return results;
    }

    void combinationSum2Recur(vector<int> &sorted_num, vector<int> &num_time, int current,
    int target, vector<int> result, vector<vector<int> > &results) {
        if (target == 0) {
            results.push_back(result);
        } else if (target > 0 && current < sorted_num.size()) {
            combinationSum2Recur(sorted_num, num_time, current+1, target, result, results);
            for(int i = 1; i <= num_time[current]; ++i) {
                int temp_target = target - i*sorted_num[current];
                if (temp_target < 0) {
                    break;
                }
                result.push_back(sorted_num[current]);
                combinationSum2Recur(sorted_num, num_time, current+1, temp_target, result, results);
            }
        }
    }
};