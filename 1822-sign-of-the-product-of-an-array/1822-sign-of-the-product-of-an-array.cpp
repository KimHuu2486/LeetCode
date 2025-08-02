class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans  = 1;
        for (int x : nums){
            if (x == 0) return 0;
            else if (x < 0) ans = 0 - ans;
        }
        return ans;
    }
};