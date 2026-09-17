class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int INF = 1e9;
        int n = arr.size(), left = 0, curSum = 0, ans = INF;
        vector<int>minLen(n, INF);

        for (int right = 0; right < n; right++) {
            curSum += arr[right]; 

            while (curSum > target) {
                curSum -= arr[left];
                left++;
            }

            if (curSum == target) {
                int len = right - left + 1;

                if (left > 0 && minLen[left - 1] != INF) {
                    ans = min(ans, len + minLen[left - 1]);
                }

                minLen[right] = min(right > 0 ? minLen[right - 1] : INF, len);
            }
            else {
                minLen[right] = (right > 0) ? minLen[right - 1] : INF;
            }
        }

        return ans == INF ? -1 : ans;
    }
};