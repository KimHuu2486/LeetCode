class Solution {
public:
    double average(vector<int>& salary) {
        int Min = INT_MAX;
        int Max = INT_MIN;
        double Sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            Min = min(Min, salary[i]);
            Max = max(Max, salary[i]);
            Sum += salary[i];
        }
        Sum -= Min + Max;
        Sum = Sum / (salary.size()-2);
        return round(Sum * 1e5) / 1e5;
    }
};