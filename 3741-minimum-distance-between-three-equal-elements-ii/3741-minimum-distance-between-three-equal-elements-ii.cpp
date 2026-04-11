class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        bool isGoodTuples = false;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() >= 3)
                isGoodTuples = true;
        }

        if (!isGoodTuples)
            return -1;

        int ans = INT_MAX;
        for (auto it : mp) {
            int n = it.second.size();
            if (n >= 3) {
                for (int i = 0; i < n - 2; i++) {
                    int a = it.second[i], b = it.second[i + 1],
                        c = it.second[i + 2];
                    int cur = (b - a) + (c - b) + (c - a);
                    ans = min(ans, cur);
                }
            }
        }

        return ans;
    }
};