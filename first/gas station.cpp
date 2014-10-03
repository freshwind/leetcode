class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int L = gas.size();
        if (L == 0) return -1;
        int start = L-1; //start location of the circle
        int end = start; //current end location
        int tank_gas = 0; //tank_gas and end location from start
        while (end != start+L) {
            if (tank_gas >= 0) {
                while (end != start+L && tank_gas >= 0) {
                    tank_gas = tank_gas - cost[end%L] + gas[end%L];
                    end++;
                }
                if (end == start+L && tank_gas >= 0) return start;
            } else {
                while (end != start+L && tank_gas < 0) {
                    start--;
                    tank_gas = tank_gas - cost[start] + gas[start];
                }
                if (end == start+L && tank_gas >= 0) return start;
            }
        }
        return -1;
    }
};