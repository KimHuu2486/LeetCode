class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
        for (int i = 0; i < bank.size(); i++) {
            int cnt = 0;
            for (char& c : bank[i]) {
                if (c == '1')
                    cnt++;
            }
            if (cnt > 0)
                count.push_back(cnt);
        }
        int ans = 0;
        if (count.size() < 2) return 0;
        for (int i = 0; i < count.size() - 1; i++) {
            ans += count[i] * count[i + 1];
        }
        return ans;
    }
};