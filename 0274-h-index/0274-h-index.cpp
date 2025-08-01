class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h = 1;
        for (int i = citations.size()-1; i>=0; i--){
            if (citations[i]>=h) h++;
            else break;
        }
        return h - 1;
    }
};