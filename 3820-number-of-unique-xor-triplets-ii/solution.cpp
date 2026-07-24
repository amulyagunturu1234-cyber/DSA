class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        int n = nums.size();

        // Store all possible XORs of two elements (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // XOR each pair XOR with every element
        for (int x : pairXor) {
            for (int num : nums) {
                tripletXor.insert(x ^ num);
            }
        }

        return tripletXor.size();
    }
};
