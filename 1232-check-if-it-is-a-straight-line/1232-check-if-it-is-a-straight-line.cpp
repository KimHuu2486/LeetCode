class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2)
            return true;
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != coordinates[0][0])
                    return false;
            }
            return true;
        } else if (coordinates[0][1] == coordinates[1][1]) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][1] != coordinates[0][1])
                    return false;
            }
            return true;
        }
        double a = (double)(coordinates[1][1] - coordinates[0][1]) /
                   (coordinates[1][0] - coordinates[0][0]);
        double b = coordinates[0][1] - a * coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++) {
            if (a * coordinates[i][0] + b != coordinates[i][1])
                return false;
        }
        return true;
    }
};