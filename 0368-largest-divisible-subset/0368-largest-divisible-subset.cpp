class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 1, curNum = -1;
        int n = nums.size();
        vector<int>index(n, 1);
        for (int i = 1; i<n; i++){
            for (int j = 0; j<i; j++ ){
                if (nums[i]%nums[j]==0 && index[i]<index[j]+1){
                    index[i] = index[j] + 1;
                    if (maxi<index[i]) {
                        maxi = index[i];
                    }
                }
            }
        }
        vector<int>ans;
        for (int i = n-1; i>=0; i--){
            if (maxi == index[i] && (curNum == -1 || curNum%nums[i] == 0)){
                ans.push_back(nums[i]);
                curNum = nums[i];
                maxi--;
            }
        }
        return ans;
    }
};