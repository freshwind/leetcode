class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int sum;
        int closest_sum = 10000;
        for (int i = 0; i <=  num.size()-3; ++i) {
            int k = num.size()-1;
            for (int j = i+1; j != k; ++j) {
                int num_ij = num[i]+num[j];
                while (target < num_ij+num[k] && k > j) {
                    --k;
                }

                if (k == num.size()-1 && target-num_ij-num[k] <= closest_sum) {
                        closest_sum = target-num_ij-num[k];
                        sum = num_ij + num[k];
                } else if (k != num.size()-1){
                    ++k;
                    if (num_ij+num[k]-target <= closest_sum) {
                        closest_sum = num_ij+num[k]-target;
                        sum = num_ij + num[k];
                    }
                    if (k != j+1 && target-num_ij-num[k-1] <= closest_sum) {
                        closest_sum = target-num_ij-num[k-1];
                        sum = num_ij + num[k-1];
                    }
                }
            }
        }
        return sum;
    }
};
