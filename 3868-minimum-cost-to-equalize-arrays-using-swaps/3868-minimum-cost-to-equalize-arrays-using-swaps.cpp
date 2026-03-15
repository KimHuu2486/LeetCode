class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq, freq1;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            freq[nums1[i]]++;
            freq[nums2[i]]++;
            freq1[nums1[i]]++;
        }

        int ans = 0;
        for (auto it: freq) {
            if (it.second % 2 == 1) return -1;
            if (freq1.count(it.first)) {
                ans += abs(it.second / 2 - freq1[it.first]);
            }
            else {
                ans += it.second / 2;
            }
        }
        return ans / 2;
    }
};