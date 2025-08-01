class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        sort(nums.begin(), nums.end());
        int dis = 0;
        for (int i = 0; i<n-1; i++){
            dis = max(dis, nums[i+1]-nums[i]);
        }
        return dis;
    }
};