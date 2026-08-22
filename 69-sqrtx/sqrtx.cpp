class Solution {
    private:
    int f(int x){
        int low=1;
        int high=x;
        int ans=1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(1LL *mid*mid<=x){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
public:
    int mySqrt(int x) {
        return f(x);
    }
};