/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int res = guess(low+(high-low)/2);
            if (res == 0)
                return low+(high-low)/2;
            else if (res == -1)
                high = low+(high-low)/2 - 1;
            else
                low = low+(high-low)/2 + 1;
        }
        return -1;
    }
};