class Solution {
private:
    const double EPS = 1e-6;

public:
    vector<double> compute(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (fabs(a) > EPS)
            res.push_back(b / a);
        if (fabs(b) > EPS)
            res.push_back(a / b);
        return res;
    }
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }
                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (dfs(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int i : cards) {
            nums.push_back((double)i);
        }
        return dfs(nums);
    }
};