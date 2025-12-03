class Solution {
public:
    long long nC2(int n) {
        if (n < 2)
            return 0;
        return 1LL * n * (n - 1) / 2;
    }
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4)
            return 0;

        // BƯỚC 1: Đếm tổng số hình thang 

        map<pair<int, int>, map<long long, set<int>>> lines;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                long long intercept =
                    1LL * dy * points[i][0] - 1LL * dx * points[i][1];

                lines[{dy, dx}][intercept].insert(i);
                lines[{dy, dx}][intercept].insert(j);
            }
        }

        long long totalCountWithDuplicates = 0;

        for (auto const& [slope, interceptMap] : lines) {
            vector<int> segmentsOnParallelLines;
            for (auto const& [val, pointSet] : interceptMap) {
                int cnt = pointSet.size();
                if (cnt >= 2) {
                    segmentsOnParallelLines.push_back(nC2(cnt));
                }
            }

            if (segmentsOnParallelLines.size() < 2)
                continue;

            long long currentSum = 0;
            long long prefixSum = 0;
            for (int count : segmentsOnParallelLines) {
                currentSum += count * prefixSum;
                prefixSum += count;
            }
            totalCountWithDuplicates += currentSum;
        }

        // BƯỚC 2: Đếm số hình bình hành (P)

        map<pair<int, int>, map<long long, int>> vectors;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int vx = points[j][0] - points[i][0];
                int vy = points[j][1] - points[i][1];

                if (vx < 0 || (vx == 0 && vy < 0)) {
                    vx = -vx;
                    vy = -vy;
                }

                int dy_slope = vy;
                int dx_slope = vx;
                int g = gcd(abs(dy_slope), abs(dx_slope));
                dy_slope /= g;
                dx_slope /= g;

                long long intercept = 1LL * dy_slope * points[i][0] -
                                      1LL * dx_slope * points[i][1];

                vectors[{vx, vy}][intercept]++;
            }
        }

        long long parallelogramCount = 0;

        for (auto const& [vec, lineMap] : vectors) {
            long long totalSegmentsSameVector = 0;
            long long collinearPairs = 0;

            for (auto const& [intercept, count] : lineMap) {
                totalSegmentsSameVector += count;
                collinearPairs += nC2(count);
            }

            parallelogramCount += nC2(totalSegmentsSameVector) - collinearPairs;
        }

        return totalCountWithDuplicates - parallelogramCount/ 2;
    }
};