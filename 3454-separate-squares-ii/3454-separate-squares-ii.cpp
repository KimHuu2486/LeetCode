class Solution {
    // Segment Tree to manage the union of x-intervals
    struct SegmentTree {
        int n;
        vector<int> count;
        vector<double> len;
        const vector<double>& X; // Reference to sorted unique X coordinates

        SegmentTree(const vector<double>& x_coords) : X(x_coords) {
            n = X.size();
            // Tree size is roughly 4 * number of elementary intervals
            count.assign(4 * n, 0);
            len.assign(4 * n, 0.0);
        }

        // update range [l, r) with value val (+1 or -1)
        // node covers X[start] ... X[end]
        void update(int node, int start, int end, int l, int r, int val) {
            if (l >= end || r <= start) return; // No overlap

            if (l <= start && end <= r) { // Total overlap
                count[node] += val;
            } else {
                int mid = start + (end - start) / 2;
                update(2 * node, start, mid, l, r, val);
                update(2 * node + 1, mid, end, l, r, val);
            }
            push_up(node, start, end);
        }

        void push_up(int node, int start, int end) {
            if (count[node] > 0) {
                // If this node is covered by at least one square, its active length is the full width
                len[node] = X[end] - X[start];
            } else if (start + 1 == end) {
                // Leaf node with count 0 -> length is 0
                len[node] = 0.0;
            } else {
                // Internal node with count 0 -> sum of children
                len[node] = len[2 * node] + len[2 * node + 1];
            }
        }
        
        double query() {
            return len[1]; // Root is at index 1
        }
    };

    struct Event {
        double y;
        int type; // 1 for add, -1 for remove
        double x1, x2;
        
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<double> unique_x;
        vector<Event> events;

        // 1. Collect coordinates and create events
        for (const auto& sq : squares) {
            double x = sq[0];
            double y = sq[1];
            double l = sq[2];
            
            unique_x.push_back(x);
            unique_x.push_back(x + l);
            
            events.push_back({y, 1, x, x + l});       // Bottom edge
            events.push_back({y + l, -1, x, x + l});  // Top edge
        }

        // 2. Coordinate Compression for X
        sort(unique_x.begin(), unique_x.end());
        unique_x.erase(unique(unique_x.begin(), unique_x.end()), unique_x.end());
        
        // Map actual x-coordinate to index in unique_x
        auto get_x_index = [&](double val) {
            return lower_bound(unique_x.begin(), unique_x.end(), val) - unique_x.begin();
        };

        sort(events.begin(), events.end());

        // 3. Sweep Line
        SegmentTree st(unique_x);
        double total_area = 0.0;
        double prev_y = events[0].y;
        
        // Store strips to avoid re-calculating or running sweep line twice
        // {height_of_strip, width_of_union}
        vector<pair<double, double>> strips;

        for (int i = 0; i < events.size(); ) {
            double curr_y = events[i].y;
            
            // Calculate area of the strip we just passed (from prev_y to curr_y)
            if (curr_y > prev_y) {
                double h = curr_y - prev_y;
                double w = st.query();
                double area = w * h;
                total_area += area;
                strips.push_back({h, w});
            }
            
            // Process all events at the current Y coordinate
            while (i < events.size() && events[i].y == curr_y) {
                int idx1 = get_x_index(events[i].x1);
                int idx2 = get_x_index(events[i].x2);
                // Update range [idx1, idx2) in segment tree
                // Range corresponds to unique_x[idx1] ... unique_x[idx2]
                st.update(1, 0, unique_x.size() - 1, idx1, idx2, events[i].type);
                i++;
            }
            prev_y = curr_y;
        }

        // 4. Find the dividing line
        double target_area = total_area / 2.0;
        double current_area = 0.0;
        double current_y = events[0].y;

        for (auto& strip : strips) {
            double h = strip.first;
            double w = strip.second;
            double strip_area = w * h;

            if (current_area + strip_area >= target_area) {
                // The answer is inside this strip
                double needed = target_area - current_area;
                // needed = w * needed_height -> needed_height = needed / w
                return current_y + (needed / w);
            }
            
            current_area += strip_area;
            current_y += h;
        }

        return current_y;
    }
};