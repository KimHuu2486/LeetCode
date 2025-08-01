class Solution {
public:
    int solve(string s, int k, int start, int end){
        if (end - start + 1 <k) return 0;
        int freq[26] = {0};
        for (int i = start; i<=end; i++){
            freq[s[i] - 'a']++;
        }
        for (int i = start; i<=end; i++){
            if (freq[s[i]- 'a']<k){
                int j = i+1;
                while (j <=end && freq[s[j]- 'a']<k) j++;
                return max(solve(s, k, start, i-1), solve(s, k, j, end));
            }
        }
        return end- start + 1;
    }
    int longestSubstring(string s, int k) {
        return solve(s, k, 0, s.size()-1);
    }
};