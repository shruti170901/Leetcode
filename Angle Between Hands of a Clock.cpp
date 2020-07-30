class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = 360.0 * minutes / 60.0;
        double h = hour % 12 * 360.0 / 12.0 + 360.0 / 12.0 * minutes / 60.0;
        if(max(m, h) - min(m, h)< 360.0 - max(m, h) + min(m, h))
            return max(m, h) - min(m, h);
        return 360.0 - max(m, h) + min(m, h);
    }
};
