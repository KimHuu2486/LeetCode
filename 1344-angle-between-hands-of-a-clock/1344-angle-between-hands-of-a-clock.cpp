class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleHour = 5.0 * hour + 5.0 * minutes / 60.0;
        if (angleHour > 60) angleHour -= 60;
        double ans = abs(minutes - angleHour) * 6.0;
        return min(ans, 360 - ans);  
    }
};