#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
        {
            return false;
        }
        else 
        {
            std::string num = std::to_string(x);
            int i =0; int j =num.size() -1;
            for (int step = 0; step <num.size() /2; step++)
            {
                if (num[i]!=num[j])
                {
                    return false;
                }
                else
                {
                    i++; j--;
                }
            }
            return true;
        }
    }
};