#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int n = prefix.size();
        for (int i = 1; i<strs.size(); i++){
            if (n==0)
            {
                return prefix;
            }
            for (int j = 0; j<n; j++){
                if (prefix[j]!=strs[i][j]){
                    n = j;
                    break;
                }
            }
            prefix.resize(n);
        }
        return prefix;
    }
};