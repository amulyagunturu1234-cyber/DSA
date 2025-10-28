class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int>mpp;
      int n=nums.size();
      for(int i=0;i<n;i++){
        int a=nums[i];
        int rest=target-a;
        if(mpp.find(rest)!=mpp.end()) return{mpp[rest],i};
       else mpp[a]=i;
    }
    return{-1,-1};     
    }
};
