class Solution {
    private:
    void check(int ind,vector<vector<int>> & ans,int target,vector<int>& candidates,vector<int> & temp ){
        //think of this take the number or no and check for the remaining target like in case of dp
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            check(i+1,ans,target-candidates[i],candidates,temp);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        int n=candidates.size();
           vector<int> temp;
           check(0,ans,target,candidates,temp);
            return ans;
    }
};
