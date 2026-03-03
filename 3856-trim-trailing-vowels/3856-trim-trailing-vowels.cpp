class Solution {
public:
    string trimTrailingVowels(string s) {
        int right = s.size() - 1;
        while (right >= 0) {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'o' ||
                s[right] == 'i' || s[right] == 'u') {
                right--;
            } else
                break;
        }
        return s.substr(0, right + 1);
    }
};