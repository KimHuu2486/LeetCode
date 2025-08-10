class Solution {
public:
    string sortDigit(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string target = sortDigit(n);
        for (int i = 0; i < 31; i++) {
            if (sortDigit(1 << i) == target)
                return true;
        }
        return false;
    }
};