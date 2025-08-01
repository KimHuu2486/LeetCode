class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        for (int num: nums){
            mp[num]++;
        }
        vector<int>ans;
        for (auto it:mp){
            if (it.second>nums.size()/3) ans.push_back(it.first);
        }
        return ans;
    }
};