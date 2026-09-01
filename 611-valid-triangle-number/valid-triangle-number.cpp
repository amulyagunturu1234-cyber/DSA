class Solution {
public:
    int triangleNumber(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int cnt = 0;

        for(int k = n - 1; k >= 2; k--) {

            int i = 0;
            int j = k - 1;

            while(i < j) {

                if((long long)arr[i] + arr[j] > arr[k]) {

                    // Every index from i to j-1 works with j and k
                    cnt += j - i;
                    j--;
                }
                else {
                    i++;
                }
            }
        }

        return cnt;
    }
};