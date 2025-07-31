class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber/26 != 0){
            if (columnNumber%26 == 0){
                result.push_back('Z');
                columnNumber/=26;
                columnNumber--;
            }
            else {
                result.push_back(columnNumber%26 -1 + 'A');
                columnNumber/=26;
            }
        }
        if (columnNumber != 0) result.push_back(columnNumber -1 + 'A');
        reverse(result.begin(), result.end());
        return result;
    }
};