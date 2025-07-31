class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MaxPro = INT_MIN;
        long long pro = 1;
        for (int i = 0; i<nums.size(); i++){
            pro*=nums[i];
            if (pro>INT_MAX) return INT_MAX;
            if (pro>MaxPro) {
                MaxPro = pro;
            }
            if (pro==0) {
                pro = 1;
            }
        }
        pro = 1;
        for (int i = nums.size()-1; i>=0 ;i--){
            pro*=nums[i];
            if (pro>INT_MAX) return INT_MAX;
            if (pro>MaxPro) {
                MaxPro = pro;
            }
            if (pro==0) {
                pro = 1;
            }
        }
        return MaxPro;
    }
};