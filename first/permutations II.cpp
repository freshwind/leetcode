class Solution {
public:
    void permuteUniqueRecur(vector<vector<int> > &results,
                            vector<int> &result,
                            vector<int> &unique_numbers,
                            vector<int> &num_time,
                            const int &L) {
        if (result.size() == L) {
            results.push_back(result);
        } else {
            for (int i = 0; i < unique_numbers.size(); ++i) {
                if (num_time[i] > 0) {
                    result.push_back(unique_numbers[i]);
                    num_time[i]--;
                    permuteUniqueRecur(results, result,
                                       unique_numbers, num_time, L);
                    result.pop_back();
                    num_time[i]++;
                }
            }

        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<int> unique_numbers;
        vector<int> num_time;
        vector<vector<int> > results;
        vector<int> result;
        if (num.size() == 0) return results;

        int L = num.size();

        //generate unique_numbers, and num_time
        sort(num.begin(), num.end());
        int current = 0;
        unique_numbers.push_back(num[0]);
        num_time.push_back(1);
        for(int i = 1; i < num.size(); ++i) {
            if (num[i] == unique_numbers[current]) {
                num_time[current]++;
            } else {
                unique_numbers.push_back(num[i]);
                num_time.push_back(1);
                current++;
            }
        }
        permuteUniqueRecur(results, result, unique_numbers, num_time, L);
        return results;
    }
};