class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int leftSum = 0, rightSum = 0;
        
        // Calculate total sum (will act as rightSum initially)
        for (int x : nums) rightSum += x;
        
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];         // exclude current element from right
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];          // include current element in left
        }
        
        return ans;
    }
};
