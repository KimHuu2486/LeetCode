class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int>mp;
        for (int& x : nums){
            int first = abs(x) % value;
            if (x < 0 && first != 0) {
                first = value - first;
            }
            mp[first]++;
        }
        int cnt = 0;
        int i = 0;
        while (mp[i] > 0) {
            mp[i++]--;
            if (i >= value) {
                i-=value;
                cnt++;
            }
        }
        return value * cnt + i;
    }
};