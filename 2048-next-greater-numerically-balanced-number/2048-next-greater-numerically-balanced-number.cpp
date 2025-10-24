class Solution {
public:
    bool isBeautiful(const vector<int>& count) {
        for (int i = 1; i <= 7; i++) {
            if (count[i] != 0 && count[i] != i) {
                return false;
            }
        }
        return true;
    }
    void generate(vector<int>& list, vector<int>& count, int num) {
        if (num > 0 && isBeautiful(count)) {
            list.push_back(num);
        }
        if (num > 1224444)
            return;
        for (int i = 1; i <= 7; i++) {
            if (count[i] < i) {
                count[i]++;
                generate(list, count, num * 10 + i);
                count[i]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<int> count(8, 0);
        vector<int> list;
        generate(list, count, 0);
        sort(list.begin(), list.end());
        for (int& num : list) {
            if (num > n)
                return num;
        }
        return 1224444;
    }
};