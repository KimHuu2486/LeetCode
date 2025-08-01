class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int min = *min_element(costs.begin(), costs.end());
        int max = *max_element(costs.begin(), costs.end());
        vector<int>freq(max-min+1);
        for (int num : costs){
            freq[num-min]++;
        }
        int ans = 0;
        for (int i = 0; i<freq.size(); i++){
            while (freq[i]>0 && i+min<=coins){
                ans++;
                coins = coins - i - min;
                freq[i]--;
            }
        }
        return ans;
    }
};