class Solution {
public:
    bool solve(vector<int>&bits, int start) {
        if (start == bits.size() - 1 && bits[start] == 0) {
            return true;
        }
        if (start >= bits.size()) return false; 
        if (bits[start] == 1) {
            return solve(bits, start + 2);
        }
        else {
            return solve(bits, start + 1);
        }

    }
    bool isOneBitCharacter(vector<int>& bits) {
        return solve(bits, 0);
    }
};