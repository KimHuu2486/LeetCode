class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long b = nums.size();
        for (int i = 0 ; i<b; i++){
            nums[i] = nums[i] - i;
        }
        sort(nums.begin(), nums.end());
        long long good = 0, same = 0;
        for (int i = 0; i<b -1; i++){
            if (nums[i] == nums[i+1]) same++;
            else{
                good = good + same * (same+1) / 2; 
                same = 0;
            }
        }
        return b * (b-1) / 2 - good - same * (same+1) / 2;
    }
};