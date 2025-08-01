class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s(nums1.begin(), nums1.end());
        unordered_set<int>temp;
        for (int i =0 ;i<nums2.size(); i++){
            if (s.count(nums2[i])){
                temp.insert(nums2[i]);
            }
        }
        return vector<int>(temp.begin(), temp.end());
    }
};