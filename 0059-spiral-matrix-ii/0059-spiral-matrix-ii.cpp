class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 1;
        vector<vector<int>>matrix;
        vector<int>temp;
        for (int i = 0; i<n; i++){
            temp.push_back(1);
        }
        for (int i = 0; i<n; i++){
            matrix.push_back(temp);
        }
        int head = 0;
        int tail = n-1;
        int count = 1;
        while (head<tail){
            for (int j = head; j<tail; j++){
                matrix[head][j] = count;
                count++;
            }
            for (int i = head; i<tail; i++){
                matrix[i][tail] = count;
                count++;
            }
            for (int j = tail; j>head; j--){
                matrix[tail][j]= count;
                count++;
            }
            for (int i = tail; i>head; i--){
                matrix[i][head] = count;
                count++;
            }
            head++; tail--;
        }
        if (head == tail){
            matrix[head][head] = count;
        }
        return matrix;
    }
};