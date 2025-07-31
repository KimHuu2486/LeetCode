class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        double left = 1, right = x;
        double epsilon = 0.00001;
        while (right - left >epsilon){
            double mid = left + (right - left) / 2;
            if (mid*mid > x){
                right = mid ;
            }
            else if (mid*mid <x){
                left = mid;
            }
            else return floor(mid);
        }
        return floor(right);
        }
    };