class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        int count = 0;
        unordered_map<int,int>fre;
        for (int i =0; i<n; i++){
            if (fre[A[i]]!=0){
                count++;
            }
            else fre[A[i]]++;
            if (fre[B[i]]!=0){
                count++;
            }
            else fre[B[i]]++;
            ans[i] = count;
        }
        return ans;
    }
};