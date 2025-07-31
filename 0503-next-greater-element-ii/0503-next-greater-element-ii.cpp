class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, -1);
        stack<int> st;
        for (int i = 0; i < n *2; i++) {
            int val = nums[i%n];
            while (!st.empty() && nums[st.top()] <val){
                vec[st.top()] = val;
                st.pop();
            }
            if (i<n){
                st.push(i);
            }
        }
        return vec;
    }
};