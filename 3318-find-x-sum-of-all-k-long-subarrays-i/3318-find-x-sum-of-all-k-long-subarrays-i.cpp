class Solution {
public:
    int x_sum(vector<int>& nums, int left, int right, const int& x) {
        int freq[51] = {};
        for (int i = left; i <= right; i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        for (int i = 1; i <= 50; i++) {
            if (freq[i]) {
                heap.push({freq[i], i});
            }
        }
        int limit = min(x, (int)heap.size());
        int sum = 0;
        for (int i = 1; i <= limit; i++) {
            auto cur = heap.top();
            heap.pop();
            sum += cur.first * cur.second;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1, 0);
        for (int i = 0; i < n - k + 1; i++) {
            ans[i] = x_sum(nums, i, i + k - 1, x);
        }
        return ans;
    }
};