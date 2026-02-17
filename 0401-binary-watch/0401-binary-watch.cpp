class Solution {
public:
    int value[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
    string standard(int hour, int minute) {
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }
    void backtracking(vector<string>& ans, int turnedOn, int start, int hour, int minute) {
        if (hour >= 12 || minute >= 60) return;

        if (turnedOn == 0) {
            ans.push_back(standard(hour, minute));
            return;
        }

        for (int i = start; i < 10; i++) {
            if (i < 4) { 
                backtracking(ans, turnedOn - 1, i + 1, hour + value[i], minute);
            } 
            else {
                backtracking(ans, turnedOn - 1, i + 1, hour, minute + value[i]);
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        backtracking(ans, turnedOn, 0, 0, 0);
        return ans;
    }
};