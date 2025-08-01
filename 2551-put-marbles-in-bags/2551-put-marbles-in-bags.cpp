class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) return 0;
        vector<int>pairSum;
        int n = weights.size();
        for (int i = 0; i<n-1; i++){
            pairSum.push_back(weights[i]+weights[i+1]);
        }
        sort(pairSum.begin(), pairSum.end());
        long long max_score = 0, min_score = 0;
        for (int i = 0; i<k-1; i++){
            max_score += pairSum[n-2-i];
            min_score +=pairSum[i];
        }
        return max_score - min_score;
    }
};