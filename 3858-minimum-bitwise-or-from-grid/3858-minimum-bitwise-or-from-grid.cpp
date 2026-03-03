class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto canAchieve = [&](int mask) {
            for (const auto& row: grid) {
                bool found_in_row = false;
                for (int x : row) {
                    if ((x | mask) == mask) {
                        found_in_row =true;
                        break;
                    }
                }
                if (!found_in_row) {
                    return false;
                }
            }
            return true;
        };

        int result = 0;
        for (int i = 16; i >= 0; i--) {
            int target_mask = result | ((1 << i) - 1);
            if (!canAchieve(target_mask)) {
                result |= (1 << i);
            }
        }

        return result;
    }
};