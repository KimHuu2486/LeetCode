class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int  n = score.size();
        vector<string>ans(n);
        priority_queue<pair<int,int>>heap;
        for (int i =0; i<n; i++){
            heap.push({score[i], i});
        }
        int count = 1;
        while (!heap.empty()){
            if (count==1){
                ans[heap.top().second] = "Gold Medal";
                count++;
            }
            else if (count==2){
                ans[heap.top().second] = "Silver Medal";
                count++;
            }
            else if (count==3){
                ans[heap.top().second] = "Bronze Medal";
                count++;
            }
            else{
                ans[heap.top().second] = to_string(count);
                count++;
            }
            heap.pop();
        }
        return ans;
    }
};