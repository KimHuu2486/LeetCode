class Solution {
public:
    bool check(string first, string second){
        int n = first.size();
        int m = second.size();
        if (n>m) return 0;
        for (int i = 0; i<n; i++){
            if (first[i]!=second[i] || first[i]!=second[m-n+i]) return 0;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i<words.size() - 1; i++){
            for (int j = i+1; j<words.size(); j++){
                count+=check(words[i], words[j]);
            }
        }
        return count;
    }
};