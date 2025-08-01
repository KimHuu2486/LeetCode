class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n%3==2) return false;
        else if (n<=3) return true;
        else if (n%3 == 1){
            return checkPowersOfThree((n-1)/3);
        }
        else return checkPowersOfThree(n/3);
    }
};