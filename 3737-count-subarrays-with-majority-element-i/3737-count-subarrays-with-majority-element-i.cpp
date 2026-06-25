class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>freq(n, 0);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                cur++;
            }
            freq[i] = cur;
        }

        int ans = cur;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int numEle = j - i + 1;
                int numTar = freq[j] - (i > 0 ? freq[i-1] : 0);
                if (numEle - numTar < numTar) {
                    ans++;
                }
            }
        }

        return ans;
    }
};