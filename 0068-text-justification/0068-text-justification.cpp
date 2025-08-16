class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i;
            int charLength = 0;
            while (j < n && charLength + words[j].size() + j - i <= maxWidth) {
                charLength += words[j].size();
                j++;
            }

            int spaces = maxWidth - charLength;
            int gaps = j - i - 1;
            string line = "";
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                while (line.size() < maxWidth)
                    line += " ";
            } else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int toAdd = spaceEach + (extra > 0 ? 1 : 0);
                        line += string(toAdd, ' ');
                        extra--;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};