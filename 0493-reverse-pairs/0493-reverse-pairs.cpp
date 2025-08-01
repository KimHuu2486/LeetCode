class Solution {
public:
    void Merge(vector<int>&nums, int low, int mid, int high, int &count){
        int j = mid+1;
        for (int i = low; i<=mid; i++){
            while(j<=high && nums[i]>2*(long long)nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        vector<int>temp(high-low+1, 0);
        int left = low, right = mid+1, k =0;
        while (left<= mid && right<=high){
            if (nums[left]<=nums[right]){
                temp[k++]=nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while (left<=mid){
            temp[k++] = nums[left++];
        }
        while (right<=high){
            temp[k++] = nums[right++];
        }
        k = 0;
        for (int i = low; i<=high; i++){
            nums[i] = temp[k++];
        }
    }
    void MergeSort(vector<int>&nums, int low, int high, int& count){
        if (low>=high) return;
        int mid = (low+high)/2;
        MergeSort(nums, low, mid, count);
        MergeSort(nums, mid+1, high, count);
        Merge(nums, low, mid, high, count);
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        MergeSort(nums, 0, nums.size()-1, count);
        return count;
    }
};