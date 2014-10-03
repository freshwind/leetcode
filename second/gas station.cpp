class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int L = gas.size();
        int start = 0;
        int to_end = 1%L;
        int gas = gas[0]-cost[0];
        while (start != to_end) {
            if (gas >= 0) {
                gas += (gas[to_end]-cost[to_end]);
                to_end = (to_end+1)%L;
            } else {
                start = (L+start-1)%L;
                gas += (gas[start]-cost[start]);
            }
        }
        return gas>=0? start:-1;
    }
};
