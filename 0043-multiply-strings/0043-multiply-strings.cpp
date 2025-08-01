class Solution {
public:

    string multiply(string num1, string num2) {
        if (num1=="0"||num2=="0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int>multi(n+m, 0);
        for (int i = m - 1; i>=0; i--){
            for (int j = n-1; j>=0; j--){
                int mul= (num1[j]-'0') * (num2[i] - '0');
                int sum = mul + multi[i+j+1];
                multi[i+j+1] = sum%10;
                multi[i+j] += sum/10; 
            }
        }
        string ans;
        for (int num:multi){
            if (!ans.empty() || num!=0){
                ans.push_back(num+'0');
            }
        }
        return ans;
    }
};