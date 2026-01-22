class Solution {
public:
    void mergePair(vector<int>& vec) {
        int minSum = INT_MAX;
        int idx = -1;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (minSum > vec[i] + vec[i + 1]) {
                minSum = vec[i] + vec[i + 1];
                idx = i;
            }
        }
        vec[idx] = minSum;
        vec.erase(vec.begin() + idx + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            mergePair(nums);
            cnt++;
        }
        return cnt;
    }
};