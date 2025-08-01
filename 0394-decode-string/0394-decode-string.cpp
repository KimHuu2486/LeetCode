class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for (char c: s){
            string temp = "";
            temp+=c;
            if (c == ']'){
                string Repeat = "";
                while (!st.empty() && st.top()!="["){
                    Repeat += st.top();
                    st.pop();
                }
                st.pop();
                string freq = "";
                while (!st.empty() && isdigit(st.top()[0])){
                    freq += st.top();
                    st.pop();
                }
                reverse(freq.begin(), freq.end());
                int n = stoi(freq);
                temp = "";
                while (n>0){
                    temp += Repeat;
                    n--;
                }
                st.push(temp);
            }
            else st.push(temp);
        }
        string ans= "";
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};