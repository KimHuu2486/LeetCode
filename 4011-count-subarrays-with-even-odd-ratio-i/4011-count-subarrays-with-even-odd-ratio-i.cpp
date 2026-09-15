class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int x = 0, y = 0;
        int ans = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    x++;
                else
                    y++;

                if (y > 0 && 1LL * x * b <= 1LL * a * y)
                    ans++;
            }
        }

        return ans;
    }
};