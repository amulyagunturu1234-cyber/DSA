class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int no=nums[i];
            int sum=0;
             while (no > 0) {
             sum =sum+ (no % 10);
             no /= 10;
             }
             nums[i]=sum;
             mini=min(mini,nums[i]);
             
        }
         return mini;
    }
};
