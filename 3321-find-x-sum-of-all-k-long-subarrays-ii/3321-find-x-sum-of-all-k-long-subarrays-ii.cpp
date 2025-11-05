class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<int, int> freq;
        multiset<pair<int, int>> top, rest;
        long long top_sum = 0;
        vector<long long> ans;

        auto balance = [&]() {
            while (top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                top.insert(*it);
                top_sum += 1LL * it->first * it->second;
                rest.erase(it);
            }
            while (top.size() > x) {
                auto it = top.begin();
                rest.insert(*it);
                top_sum -= 1LL * it->first * it->second;
                top.erase(it);
            }
            while (!top.empty() && !rest.empty() &&
                   *top.begin() < *prev(rest.end())) {
                auto it1 = top.begin();
                auto it2 = prev(rest.end());
                top_sum += 1LL * it2->first * it2->second -
                           1LL * it1->first * it1->second;
                top.insert(*it2);
                rest.insert(*it1);
                rest.erase(it2);
                top.erase(it1);
            }
        };

        auto add = [&](int num) {
            pair<int, int> old = {freq[num], num};
            if (top.find(old) != top.end()) {
                top.erase(top.find(old));
                top_sum -= 1LL * old.first * old.second;
            } else if (rest.find(old) != rest.end()) {
                rest.erase(rest.find(old));
            }
            freq[num]++;
            rest.insert({freq[num], num});
            balance();
        };

        auto remove = [&](int num) {
            pair<int, int> old = {freq[num], num};
            if (top.find(old) != top.end()) {
                top.erase(top.find(old));
                top_sum -= 1LL * old.first * old.second;
            } else {
                rest.erase(rest.find(old));
            }
            freq[num]--;
            if (freq[num] == 0) {
                freq.erase(num);
            } else {
                rest.insert({freq[num], num});
            }
            balance();
        };

        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        ans.push_back(top_sum);

        for (int i = k; i < (int)nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);
            ans.push_back(top_sum);
        }
        return ans;
    }
};