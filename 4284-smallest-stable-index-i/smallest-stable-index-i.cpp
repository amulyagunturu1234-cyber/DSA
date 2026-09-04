class Solution {
    int insScore(int ind,vector<int>& nums){
        int maxm=INT_MIN;
        int minm=INT_MAX;
        for(int i=0;i<=ind;i++){
            maxm=max(maxm,nums[i]);
        }
        for(int j=ind;j<nums.size();j++){
            minm=min(minm,nums[j]);
        }
        return (maxm-minm);
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
    
        for(int i=0;i<nums.size();i++){
            int num=insScore(i,nums);
            if(num<=k){
                return i;
            }
        }
        return -1;
    }
};