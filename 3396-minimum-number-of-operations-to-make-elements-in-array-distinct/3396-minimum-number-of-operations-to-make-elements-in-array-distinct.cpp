class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>map(101, 0);
        int i = nums.size()-1;
        for (i; i>=0; i--){
            if (map[nums[i]]>0) return ceil((double)(i+1)/3);
            map[nums[i]]++;
        }
        return 0;
    } 
};