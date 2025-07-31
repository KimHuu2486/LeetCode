class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for (auto it:mp){
            if (it.second == 1) return it.first;
        }
        return 0;
    }
};