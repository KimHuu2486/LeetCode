class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(), nums.end());
        vector<int>count(max-min+1, 0);
        for (int num:nums){
            count[num-min]++;
        }
        int index = 0;
        for (int i = 0; i<count.size(); i++){
            while(count[i]!=0){
                nums[index] = i + min;
                count[i]--;
                index++;
            }
        }
        return nums;
    }
};