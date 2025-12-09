class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        unordered_map<int, int> freqPrev;
        unordered_map<int, int> freqNext;
        for (int i = 2; i < n; i++) {
            freqNext[nums[i]]++;
        }

        freqPrev[nums[0]]++;
        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int need = nums[i] * 2;
            if (freqPrev.find(need) != freqPrev.end() && freqPrev[need] > 0) {
                if (freqNext.find(need) != freqNext.end() && freqNext[need] > 0) {
                    ans = (ans + 1LL * freqNext[need] * freqPrev[need]) % MOD;
                } 
            }
            freqPrev[nums[i]]++;
            freqNext[nums[i + 1]]--;
        }
        return ans;
    }
};