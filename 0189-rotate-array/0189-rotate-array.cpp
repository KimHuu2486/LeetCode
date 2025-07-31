class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if (k==0){
            return;
        }
        vector<int>vec;
        for (int i = nums.size()-k; i<nums.size(); i++){
            vec.push_back(nums[i]);
        }
        for (int i = 0; i<nums.size() - k; i++){
            vec.push_back(nums[i]);
        }
        nums = vec;
    }
};