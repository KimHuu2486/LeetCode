class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0LL;
        int l = 0;

        deque<int> minDeque;
        deque<int> maxDeque;
        
        for (int r = 0; r < n; r++) {
            // Phan tu o front la max
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);

            // Phan tu o front la min
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            int var = nums[r];

            while (l < r) {
                long long curMax = nums[maxDeque.front()];
                long long curMin = nums[minDeque.front()];
                long long length = 0LL + r - l + 1;

                if ((curMax - curMin) * length > k) {
                    l++;
                    if (!maxDeque.empty() && maxDeque.front() < l) {
                        maxDeque.pop_front();
                    }
                    if (!minDeque.empty() && minDeque.front() < l) {
                        minDeque.pop_front();
                    }
                }
                else break;
            }
            ans += r - l + 1;
        }

        return ans;
    }
};