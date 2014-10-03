class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > results;
        vector<int> result;
        if (S.size() == 0) {
            return results;
        }
        sort(S.begin(), S.end());
        vector<int> unique_numbers;
        vector<int> appear_times;
        unique_numbers.push_back(S[0]);
        appear_times.push_back(1);
        int probe = 0;
        for (int i = 1; i != S.size(); ++i) {
            if (S[i] == unique_numbers[probe]) {
                appear_times[probe]++;
            } else {
                unique_numbers.push_back(S[i]);
                appear_times.push_back(1);
                probe++;
            }
        }
        subsetRecur(unique_numbers, appear_times, 0, result, results);
        return results;
    }

    void subsetRecur(vector<int> &unique_numbers, vector<int> &appear_times,
                 int current, vector<int> result,
                 vector<vector<int> > &results) {
        if (current == unique_numbers.size()) {
            results.push_back(result);
        } else {
            subsetRecur(unique_numbers, appear_times, current+1, result, results);
            for (int i = 0; i != appear_times[current]; ++i) {
                result.push_back(unique_numbers[current]);
                subsetRecur(unique_numbers, appear_times, current+1, result,
                            results);
            }
        }
    }
};