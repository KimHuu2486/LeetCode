class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int n = gas.size();
        int start = 0, curGas = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                curGas = 0;
                start = i + 1;
            }
        }
        if (totalGas < totalCost)
            return -1;
        return start;
    }
};