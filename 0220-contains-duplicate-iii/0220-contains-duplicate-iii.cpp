class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int>window;
        for (int i = 0; i<nums.size(); i++){
            if(i>indexDiff){
                window.erase(window.find(nums[i-indexDiff-1]));
            }
            
            auto it = window.lower_bound(nums[i]-valueDiff);
            if (it!=window.end() && *it<=valueDiff+nums[i]) return 1;
            window.insert(nums[i]);
        }
        return 0;
    }
};