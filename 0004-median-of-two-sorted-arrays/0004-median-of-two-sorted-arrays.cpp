class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>vec;
        int left1 = 0;
        int left2 = 0;
        while(left1<m && left2<n){
            if (nums1[left1]<nums2[left2]){
                vec.push_back(nums1[left1]);
                left1++;
            }
            else{
                vec.push_back(nums2[left2]);
                left2++;
            }
        }
        if(left1<m) {
            for (int i = left1; i<m; i++){
                vec.push_back(nums1[i]);
            }
        }
        if (left2<n){
            for (int i = left2; i<n; i++){
                vec.push_back(nums2[i]);
            }
        }
        if ((m+n)%2 == 0){
            int idx = (m+n) / 2;
            return (vec[idx] + (double)vec[idx - 1]) / 2;
        }
        else{
            return (double)vec[(m+n)/2];
        }
    }
};