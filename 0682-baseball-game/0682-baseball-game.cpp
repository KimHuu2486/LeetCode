class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string& s: operations){
            if (s == "C"){
                st.pop();
            }
            else if (s == "D"){
                st.push(2 * st.top());
            }
            else if (s == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);         
                st.push(top1 + top2); 
            }
            else st.push(stoi(s));
        }
        int ans = 0;
        while (!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};