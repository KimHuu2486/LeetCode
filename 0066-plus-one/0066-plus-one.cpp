class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =digits.size();
        digits[n-1]++;
        for (int i = n-1; i>=0; i--){
            if (digits[i]==10){
                digits[i]=0;
                if (i == 0){
                    digits.insert(digits.begin(), 1);
                }
                else{
                    digits[i-1]++;
                }
            }
            else break;
        }
        return digits;
    }
};