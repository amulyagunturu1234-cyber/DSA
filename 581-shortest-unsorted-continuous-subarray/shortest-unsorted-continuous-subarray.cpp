class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int stind=-1;
        int endind=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                stind=i-1;
                break;
            }
        }
           if(stind==-1) return 0; 
           for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                endind=i;
                break;
            }
           }
           int mn=INT_MAX;
           int mx=INT_MIN;
           for(int i=stind;i<=endind;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
           }
           while(stind>0 && nums[stind-1]>mn){
            stind--;
           }
           while(endind<n-1 && nums[endind+1]<mx) endind++;
           return endind-stind+1;
    }
};