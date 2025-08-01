class Solution {
public:
    bool CheckSubString(string a, vector<int>fre){
        for (char c:a){
            fre[c-97]--;
        }
        for (int i : fre){
            if (i>0) return 0;
        }
        return 1;
    }
    void AddTwoVector(vector<int>&a, vector<int>b){
        for (int i = 0; i<a.size(); i++){
            a[i] = max(a[i], b[i]);
        }
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>fre(26,0);
        for (string t:words2){
            vector<int>temp(26,0);
            for (char c:t){
                temp[c-97]++;
            }
            AddTwoVector(fre,temp);
        }
        for (string t:words1){
            if (CheckSubString(t, fre)) ans.push_back(t);
        }
        return ans;
    }
};