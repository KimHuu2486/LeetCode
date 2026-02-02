class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long current_sum = 0;
        multiset<int> low, high;
        
        // Mục tiêu: Chọn k-1 phần tử nhỏ nhất trong cửa sổ size (dist + 1)
        int target_size = k - 1; 

        auto add = [&](int val) {
            low.insert(val);
            current_sum += val;
            if (low.size() > target_size) {
                int max_val = *low.rbegin();
                current_sum -= max_val;
                high.insert(max_val);
                low.erase(prev(low.end()));
            }
        };

        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                current_sum -= val;
                low.erase(it);
                if (!high.empty()) {
                    int min_high = *high.begin();
                    current_sum += min_high;
                    low.insert(min_high);
                    high.erase(high.begin());
                }
            } else {
                high.erase(high.find(val));
            }
        };

        for (int i = 1; i <= dist + 1; ++i) {
            add(nums[i]);
        }

        long long min_cost = nums[0] + current_sum;


        for (int i = dist + 2; i < n; ++i) {
            remove(nums[i - dist - 1]);
            add(nums[i]);   
            min_cost = min(min_cost, nums[0] + current_sum);
        }

        return min_cost;
    }
};