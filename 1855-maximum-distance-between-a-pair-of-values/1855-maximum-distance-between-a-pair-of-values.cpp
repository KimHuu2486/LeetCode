class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();

        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j + 1 < m && nums1[i] <= nums2[j + 1]) {
                j++;
            }
            ans = max(ans, j - i);
        }

        return ans;
    }
};