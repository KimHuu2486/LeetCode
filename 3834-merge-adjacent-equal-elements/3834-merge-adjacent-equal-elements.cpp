class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>stack;
        stack.reserve(nums.size());

        for (int& num: nums) {
            long long cur = 0LL + num;

            while (!stack.empty() && stack.back() == cur) {
                cur += stack.back();
                stack.pop_back();
            }

            stack.push_back(cur);
        }

        return stack;
    }
};