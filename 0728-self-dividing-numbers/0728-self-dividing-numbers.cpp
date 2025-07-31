class Solution {
public:
    bool Check(int n){
        int x =n;
        while(n>0){
            if (n%10==0){
                return 0;
            }
            if (x % (n%10) == 0){
                n/=10;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        for (int i=left; i<=right; i++){
            if(Check(i)){
                vec.push_back(i);
            }
        }
        return vec;
    }
};