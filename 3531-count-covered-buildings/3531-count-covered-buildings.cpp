class Solution {
public:
    long long keyOf(int x, int y) {
        return ( (long long)x << 32 ) ^ (unsigned long long)y;
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();

        unordered_set<long long> innerOnRow; 
        innerOnRow.reserve(m * 2);

        sort(buildings.begin(), buildings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });

        int i = 0;
        while (i < m) {
            int x = buildings[i][0];
            int j = i + 1;
            while (j < m && buildings[j][0] == x)
                j++;
            if (j - i >= 3) {
                for (int k = i + 1; k <= j - 2; ++k) {
                    int ytemp = buildings[k][1];
                    innerOnRow.insert(keyOf(x, ytemp));
                }
            }
            i = j;
        }

        sort(buildings.begin(), buildings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });

        int cnt = 0;
        i = 0;
        while (i < m) {
            int y = buildings[i][1];
            int j = i + 1;
            while (j < m && buildings[j][1] == y)
                j++;
            if (j - i >= 3) {
                for (int k = i + 1; k <= j - 2; ++k) {
                    int xtemp = buildings[k][0];
                    if (innerOnRow.count(keyOf(xtemp, y)) == true) {
                        cnt++;
                    }
                }
            }
            i = j;
        }

        return cnt;
    }
};