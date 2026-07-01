class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_a = -1, last_b = -1, last_c = -1;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') last_a = i;
            else if (s[i] == 'b') last_b = i;
            else last_c = i;

            if (last_a != -1 && last_b != -1 && last_c != -1) {
                int min_last = min({last_a, last_b, last_c});
                count += (min_last + 1);
            }
        }

        return count;
    }
};