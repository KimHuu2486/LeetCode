class Solution {
public:
    bool isHappy(int n) {
        while(n>9){
            int x = 0;
            while(n>0){
                int temp = n%10;
                x+=temp*temp;
                n/=10;
            }
            n = x;
        }
        if (n==1 || n==7) return true;
        return false;
    }
};