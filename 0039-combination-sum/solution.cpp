class Solution {
    private:
    void check(int ind,vector<vector<int>> & ans,int target,vector<int>& candidates,vector<int> & temp ){
        //think of this take the number or no and check for the remaining target like in case of dp
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        if(ind==candidates.size()) return;
        if(candidates[ind]<=target){//taking the current element
            temp.push_back(candidates[ind]);
            check(ind,ans,target-candidates[ind],candidates,temp);//using the
            temp.pop_back();
        }
        check(ind + 1, ans, target, candidates, temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
           vector<int> temp;
           check(0,ans,target,candidates,temp);
            return ans;
    }
};
