class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        auto rotateRight = [&]() {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
            return mat;
        };

        auto compareMat = [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j])
                        return false;
                }
            }
            return true;
        };

        if (compareMat())
            return true;

        for (int i = 1; i < 4; i++) {
            rotateRight();
            if (compareMat())
                return true;
        }
        return false;
    }
};