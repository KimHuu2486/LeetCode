class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        vector<int> st;
        int cnt = 0;
        for (int& num: nums) {
            while (!st.empty() && num < st.back()) {
                st.pop_back();
                cnt++;
            }
            if (st.empty() || num > st.back()) {
                st.push_back(num);
            }
        }
        return cnt;
    }
};