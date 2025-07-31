class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int remember = 0;
        int temp;
        string result = "";
        while (i>=0||j>=0||remember!=0){
            temp = remember;
            if (i>=0){
                temp += a[i] - '0';
                i--;
            }
            if (j>=0){
                temp += b[j] - '0';
                j--;
            }
            result += temp % 2 + '0';
            remember = temp / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};