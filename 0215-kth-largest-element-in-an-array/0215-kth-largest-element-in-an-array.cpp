class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxvalue = *max_element(nums.begin(), nums.end());
        int minvalue = *min_element(nums.begin(), nums.end());
        vector<int>fregency(maxvalue-minvalue+1, 0);
        for (int num: nums){
            fregency[num-minvalue]++;
        }
        for (int i = fregency.size() -1; i>=0 ;i--){
            k-=fregency[i];
            if (k<=0) return i+minvalue;
        }
        return 0;
    }
};