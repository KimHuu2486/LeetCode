class Solution {
public:
    bool checkLetters(char s){
        return (('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z') || ('0' <= s && s <= '9'));
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() -1;
        while(left<right){
            while (left < right && !checkLetters(s[left])) left++;
            while (left < right && !checkLetters(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return 1;
    }
};