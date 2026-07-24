class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = nums.size() - 1;
        int i = 0;

        while (i <= end) {
            if (nums[i] == val) {
                while (i <= end && nums[end] == val)
                    end--;

                if (i > end) break;

                swap(nums[i], nums[end]);
                end--;
            } else {
                i++;
            }
        }

        return end + 1; 
    }
};
