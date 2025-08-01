class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st= {'A', 'E', 'I', 'O', 'U', 'a','e','i', 'o', 'u'};
        int left = 0;
        int n = s.size();
        int right = n -1;
        while (left<right){
            while(left<right && !st.count(s[left])){
                left++;
            }
            while (right>left && !st.count(s[right])){
                right--;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};