#include <string>
class Solution {
    public:
    string makeFancyString(string s) {
char pre = '@';
int i = 0;
for (int len = 0; char c:s)
{
    if (pre!=c)
    {
        len = 1;
    }
    else len++;
    if (len<=2)
    {
        s[i] = c;
        i++;
        pre = c;
    }
}
s.resize(i);
return s;
    }
};