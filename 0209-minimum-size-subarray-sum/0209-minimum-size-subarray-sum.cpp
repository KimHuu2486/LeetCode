class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>prefix(nums.size()+1, 0);
        int temp = 0;
        for (int i = 0; i<nums.size(); i++){
            temp+=nums[i];
            prefix[i+1] = temp;
        }
        int mindis= 0;
        int left = 0;
        int right = 1;
        while(right<nums.size()+1){
            if (prefix[right] - prefix[left] <target){
                right++;
            }
            else{
                if (mindis == 0) mindis = right - left;
                else mindis = min(mindis, right-left);
                left++;
            }
            
        }
        return mindis;

    }
};