class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ball = 0;
        int step = 0;
        vector<int>left(n,0);
        for (int i = 0; i<n; i++){
            left[i] = step;
            if (boxes[i]=='1') ball++;
            step+=ball;
        }
        ball = 0;
        step = 0;
        vector<int>right(n,0);
        for (int i = n-1; i>=0; i--){
            right[i] =step;
            if (boxes[i]=='1') ball++;
            step+=ball;
        }
        vector<int>ans(n, 0);
        for (int i = 0; i<n; i++){
            ans[i] = left[i]+right[i];
        }
        return ans;
    }
};