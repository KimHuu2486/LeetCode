class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int farthest = 0;
        int jump = 0;
        for (int i = 0; i<n-1; i++){
            farthest = max(farthest, i+nums[i]);
            if (i == cur){
                jump++;
                cur = farthest;
            }
        }
        return jump;
    }
};