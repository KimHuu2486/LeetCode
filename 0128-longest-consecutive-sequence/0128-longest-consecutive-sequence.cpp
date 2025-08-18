class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int length = 1;
                while (st.find(num + length) != st.end()) {
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};