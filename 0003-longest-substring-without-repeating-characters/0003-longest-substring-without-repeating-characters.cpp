class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fre[128] = { };
        int ans = 0;
        int left = 0; 
        int right = 0;
        while(right<s.size()){
            fre[s[right]]++;
            while(fre[s[right]]>1){
                fre[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};