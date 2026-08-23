class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        if(n>0 && lower<=nums[0]-1){
            int a=lower;
            int b=min(upper,nums[0]-1);
            ans.push_back({a,b});
        }
        for(int i=1;i<n;i++){
            int a=max(lower,nums[i-1]+1);
            int b=min(upper,nums[i]-1);
            if(a<=b) ans.push_back({a,b});
        }
        if(n>0 && nums[n-1]+1<=upper){
            int a=max(lower,nums[n-1]+1);
            int b=upper;
            if(a<=b) ans.push_back({a,b});
        }
        return ans;
    }
};