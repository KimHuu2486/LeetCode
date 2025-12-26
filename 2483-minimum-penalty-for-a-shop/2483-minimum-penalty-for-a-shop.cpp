class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for (const char& c: customers) {
            if (c == 'Y') {
                penalty++;
            }
        }

        int ans = 0;
        int ans_pen = penalty;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;
                if (penalty < ans_pen) {
                    ans_pen = penalty;
                    ans = i + 1;
                }
            }
            else {
                penalty++;
            }
        }
        
        return ans;
    }
};