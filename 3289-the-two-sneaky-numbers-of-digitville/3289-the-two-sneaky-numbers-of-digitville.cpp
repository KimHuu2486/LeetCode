class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n - 2, 0);
        vector<int>ans;
        for (const int& i: nums) {
            freq[i]++;
            if (freq[i] >= 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};