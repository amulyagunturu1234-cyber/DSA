class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=nums[i];
            int digit=0;
            int sum=0;
            while(temp){
                int digit=temp%10;
                sum+=digit;
                temp=temp/10;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};