class Solution {
public:
    int convertBinToDec(const string& bin) {
        int dec = 0;
        for (char c : bin) {
            dec = (dec << 1) | (c - '0');
        }
        return dec;
    }

    string convertDecToBinary(int num, int len) {
        string ans = "";
        while (num > 0) {
            ans += (num % 2) + '0';
            num /= 2;
        }
        while (ans.size() < len) {
            ans += '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int>numsDec;
        for (int i = 0; i < n; i++) {
            numsDec.insert(convertBinToDec(nums[i]));
        }

        int res = 0;
        while (numsDec.count(res)) {
            res++;
        }

        return convertDecToBinary(res, n);
    }
};