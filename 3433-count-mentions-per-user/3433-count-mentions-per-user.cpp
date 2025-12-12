class Solution {
public:
    vector<int> parse(const string& s) {
        stringstream ss(s);
        vector<int> idx;
        string temp;
        while (ss >> temp) {
            temp = temp.substr(2);
            idx.push_back(stoi(temp));
        }
        return idx;
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int time_a = stoi(a[1]);
                 int time_b = stoi(b[1]);
                 if (time_a == time_b) {
                     return a[0] > b[0];
                 }
                 return time_a < time_b;
             });

        vector<bool> onl(numberOfUsers, true);
        vector<int> ans(numberOfUsers, 0);
        queue<pair<int, int>> q;

        for (auto& cur : events) {
            string event = cur[0];
            int time = stoi(cur[1]);
            string mention = cur[2];
            while (!q.empty() && q.front().second <= time) {
                onl[q.front().first] = true;
                q.pop();
            }

            if (event == "MESSAGE") {
                if (mention == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        ans[i]++;
                    }
                } else if (mention == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (onl[i]) {
                            ans[i]++;
                        }
                    }
                } else {
                    vector<int> idx = parse(mention);
                    for (int i : idx) {
                        ans[i]++;
                    }
                }
            } else {
                int id = stoi(mention);
                onl[id] = false;
                q.push({id, time + 60});
            }
        }
        return ans;
    }
};