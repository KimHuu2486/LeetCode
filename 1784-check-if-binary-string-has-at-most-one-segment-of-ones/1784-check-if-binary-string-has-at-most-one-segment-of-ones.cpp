class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool zeros = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                zeros = true;
            } 
            else {
                if (zeros) return false;
            }
        }
        return true;
    }
};