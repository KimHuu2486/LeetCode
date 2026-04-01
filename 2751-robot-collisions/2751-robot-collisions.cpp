class Solution {
    struct info {
        int pos, health;
        char dir;
        int init_pos;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<info> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.pos < b.pos; });

        stack<info> st;
        for (int i = 0; i < n; i++) {
            info cur = vec[i];
            if (cur.dir == 'R') {
                st.push(cur);
            } else {
                bool isDestroyed = false;

                while (!st.empty()) {
                    info temp = st.top();
                    if (temp.dir == 'L')
                        break;
                    st.pop();

                    if (temp.health == cur.health) {
                        isDestroyed = true;
                        break;
                    } else if (temp.health > cur.health) {
                        temp.health--;
                        st.push(temp);
                        isDestroyed = true;
                        break;
                    } else {
                        cur.health--;
                    }
                }

                if (!isDestroyed) {
                    st.push(cur);
                }
            }
        }

        vector<info> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        sort(res.begin(), res.end(),
             [](auto& a, auto& b) { return a.init_pos < b.init_pos; });

        int m = res.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = res[i].health;
        }

        return ans;
    }
};