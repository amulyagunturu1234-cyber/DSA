class Solution {
public:
    double angleClock(int hour, int minutes) {
         double minuteAngle = minutes * 6.0;
        
        // Hour hand angle from 12 o'clock
        // Hour hand also moves as minutes progress (0.5° per minute)
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        // Difference between the two angles
        double diff = abs(minuteAngle - hourAngle);
        
        // Return the smaller angle (at most 180°)
        return min(diff, 360.0 - diff);
    }
};
