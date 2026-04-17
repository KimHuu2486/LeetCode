class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            ans *= 10;
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size(), ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (mpp.count(nums[i])) {
                ans = min(ans, i - mpp[nums[i]]);
            }
            mpp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};