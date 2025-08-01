class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int left = 0;
        while(left<nums.size()){
            if (left == nums.size()-1){
                ans.push_back(to_string(nums[left]));
                return ans;
            }
            int right = left + 1;
            while (right<nums.size() && nums[right] == nums[right-1] + 1){
                right++;
            }
            if (right == left +1){
                ans.push_back(to_string(nums[left]));
                left++;
            }
            else {
                ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right-1]));
                left = right;
            }
        }    
        return ans;
    }
};