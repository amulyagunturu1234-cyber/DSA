class Solution {
    private:
    double func(vector<int>&piles,int hrs){
        int n=piles.size();
        double tothrs=0;
        for(int i=0;i<n;i++){
            tothrs+=ceil((double)piles[i]/hrs);
        }
        return tothrs;
    }
    int f(vector<int> &piles,int h){
        int n=piles.size();
        int low=1;
        int ans=INT_MAX;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(func(piles,mid)<=h){
                ans=mid;
                 high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return f(piles,h);
    }
};