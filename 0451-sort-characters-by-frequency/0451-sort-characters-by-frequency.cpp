class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>fre;
        for (char c:s){
            fre[c]++;
        }
        priority_queue<pair<int,char>>heap;
        for (auto it:fre){
            heap.push({it.second,it.first});
        }
        string ans;
        while(!heap.empty()){
            for (int i = 1; i<=heap.top().first; i++){
                ans+=heap.top().second;
            }
            heap.pop();
        }
        return ans;

    }
};