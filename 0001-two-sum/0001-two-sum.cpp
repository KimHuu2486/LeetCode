class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>vec(n);
        for (int i = 0; i<n; i++){
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        int l = 0, r= n-1;
        while (l<r){
            if (vec[l].first + vec[r].first<target){
                l++;
            }
            else if (vec[l].first + vec[r].first>target){
                r--;
            }
            else return {vec[l].second, vec[r].second};
        }
        return {};
    }
};