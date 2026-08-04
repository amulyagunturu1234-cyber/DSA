class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int minm=INT_MAX;
        int maxm=INT_MIN;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>maxm) maxm=nums[i];
            if(nums[i]<minm) minm=nums[i];
            
        }
        vector<int>hash(maxm+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=minm;i<maxm;i++){
            if(hash[i]==0) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
