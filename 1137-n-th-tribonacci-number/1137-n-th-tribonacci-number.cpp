class Solution {
public:
    int tribonacci(int n) {
        if (n<3) return n!=0;
        int n0 = 0, n1=1, n2=1;
        for (int i = 3;i<=n; i++){
            int n3 = n0+n1+n2;
            n0 = n1;
            n1= n2;
            n2 = n3;
        }
        return n2;
    }
};