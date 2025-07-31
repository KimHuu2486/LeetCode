class Solution {
public:
    int countPrimes(int n) {
        if (n<2) return 0;
        vector<bool>vec(n, 1);
        int count = 0;
        for (int i = 2; i<n; i++){
            if (vec[i]){
                count++;
                for (long j = (long)i*i; j<n; j+=i){
                    vec[j] = 0;
                }
            }
        }
        return count;
    }
};