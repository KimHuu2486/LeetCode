class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return false;
            else if (nums[i] > nums[i - 1]) {
                if (cnt == 1) {
                    cnt++;
                }
            }
            else {
                if (cnt == 0 || cnt == 2) {
                    cnt++;
                }
                if (cnt > 2) return false;
            }
        }
        return cnt == 2 && nums[1] > nums[0];
    }
};