class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long ans = mass + 0LL;
        for (const int& cur: asteroids) {
            if (ans < cur) return false;
            ans += cur;
        }
        return true;
    }
};