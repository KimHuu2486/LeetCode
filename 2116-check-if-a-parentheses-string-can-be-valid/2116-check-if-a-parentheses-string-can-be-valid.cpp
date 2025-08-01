class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n%2!=0) return false;
        stack<int>open , flexible;
        for (int i =0; i<n; i++){
            if (s[i] == '(' && locked[i]=='1'){
                open.push(i);
            }
            else if (s[i] ==')' && locked[i] =='1'){
                if (!open.empty()) open.pop();
                else {
                    if (!flexible.empty()) flexible.pop();
                    else return 0;
                }
            }
            else flexible.push(i);
        }
        while (!open.empty()&& !flexible.empty()){
            if (open.top()>flexible.top()) return 0;
            open.pop();
            flexible.pop();
        }
        return open.empty();
    }
};