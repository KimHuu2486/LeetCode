class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxSize = 0;
        for (int i = 0; i<s.size(); i++){
            int left = i;
            int right = i;
            while (left>=0 && right<s.size()){
                if (s[left] == s[right]){
                    left--;
                    right++;
                }
                else break;
            }
            if (maxSize< right-left-1){
                maxSize = right - left - 1;
                ans = s.substr(left+1, maxSize);
            }
            left = i; 
            right = i+1;
            while (left>= 0 && right<s.size()){
                if (s[left] == s[right]){
                    left--;
                    right++;
                }
                else break;
            }
            if (maxSize< right-left-1){
                maxSize = right - left - 1;
                ans = s.substr(left+1, maxSize);
            }
        }
        return ans;
    }
};