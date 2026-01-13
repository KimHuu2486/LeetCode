class Solution {
public:
    double binarySearch(const vector<vector<int>>& squares, double left, double right, const double& target) {
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            double areaBottom = 0.0f;
            for (auto& square: squares) {
                if (square[1] + square[2] < mid) {
                    areaBottom += (double)square[2] * square[2];
                }
                else if (square[1] > mid) {
                    continue;
                }
                else {
                    areaBottom += (double)square[2] * (mid - square[1]);
                }
            }
            double delta = areaBottom - target;
            if (delta < 0) {
                left = mid;
            }
            else {
                right = mid;
            };
        }
        return left;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0f;
        double low = 1000000000.0f, high = 0.0f;
        for (auto& square: squares) {
            totalArea += (double)square[2] * square[2];
            low = min(low, (double)square[1]);
            high = max(high, (double)square[1] + square[2]);
        }

        double target = totalArea / 2.0f;

        return binarySearch(squares, low, high, target);
          
    }
};