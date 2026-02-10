class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l <  n - 1; l++) {
            unordered_map<int, int> freq;
            int even = 0, odd = 0;

            for (int r = l; r < n; r++) {
                int x = nums[r];

                if (++freq[x] == 1) {
                    if (x % 2 == 0) odd++;
                    else even++;
                }

                if (odd == even) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};