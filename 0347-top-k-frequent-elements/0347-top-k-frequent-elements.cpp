class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>frequent;
        for(int num:nums){
            frequent[num]++;
        }
        priority_queue<pair<int,int>>heapMax;
        for (auto it:frequent){
            heapMax.push({it.second, it.first});
        }
        vector<int>ans;
        for (int i = 1; i<=k; i++){
            ans.push_back(heapMax.top().second);
            heapMax.pop();
        }
        return ans;
    }
};