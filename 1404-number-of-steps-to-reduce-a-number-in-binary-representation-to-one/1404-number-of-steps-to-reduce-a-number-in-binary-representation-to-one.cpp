class Solution {
public:
    void addOne(string& s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if (i >= 0) {
            s[i] = '1';
        } else {
            s.insert(s.begin(), '1');
        }
    }
    int numSteps(string s) {
        int cnt = 0;
        while (s != "1") {
            if (s.back() == '1') {
                addOne(s);
            } else {
                s.pop_back();
            }
            cnt++;
        }
        return cnt;
    }
};