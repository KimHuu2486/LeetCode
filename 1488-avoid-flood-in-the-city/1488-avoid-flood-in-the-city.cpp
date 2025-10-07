class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lastRain;
        set<int>dryDays;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0){
                dryDays.insert(i);
                continue;
            }
            res[i] = -1;
            if (lastRain.count(lake)){
                int prev = lastRain[lake];
                auto it = dryDays.upper_bound(prev);
                if (it == dryDays.end() || *it >= i) return {};
                res[*it] = lake;
                dryDays.erase(*it);
            }
            lastRain[lake] = i;
        }
        return res;
    }
};