class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while (left<right){
            if (s[left] != s[right]) return 0;
            left++;
            right--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int left = 0; 
        int right = s.size() - 1;
        while (left<right){
            if (s[left]!=s[right]){
                return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right);
            }
            left++;
            right--;
        }
        return 1;
    }
};