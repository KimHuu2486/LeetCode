class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int freq[1001] ={};
        for (int x : arr1){
            freq[x]++;
        }
        vector<int>ans(arr1.size());
        int cur = 0;
        for (int x : arr2){
            while (freq[x]>0){
                ans[cur] = x;
                freq[x]--;
                cur++;
            }
        }
        for (int i = 0; i<=1000; i++){
            while (freq[i]>0){
                ans[cur] = i;
                freq[i]--;
                cur++;
            }
        }
        return ans;
    }
};