class Solution {
public:
    int powmod(int a, int b){
        a%=1337;
        int res = 1;
        for (int i = 1; i<=b; i++){
            res = (res * a) %1337;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = *b.rbegin();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % 1337;
    }
};