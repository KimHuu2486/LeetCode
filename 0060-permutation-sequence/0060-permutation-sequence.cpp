class Solution {
public:
    void setPerm(vector<int>&vec, string&result, int &n, int &k, vector<int>factVal){
        if (n==1){
            result+=to_string(vec.back());
            return;
        }
        int index = k/factVal[n-1];
        if (k%factVal[n-1]==0){
            index--;
        }
        result+=to_string(vec[index]);
        vec.erase(vec.begin() + index);
        k = k - index * factVal[n-1];
        n--;
        setPerm(vec, result, n, k, factVal);
    }
    string getPermutation(int n, int k) {
        if (n==1) return "1";
        vector<int>factVal = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string result ="";
        vector<int>vec;
        for (int i = 1; i<=n; i++){
            vec.push_back(i);
        }
        setPerm(vec, result, n, k, factVal);
        return result;
    }
};