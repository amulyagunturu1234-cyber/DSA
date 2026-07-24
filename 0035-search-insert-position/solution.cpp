class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int up=0;
        if(target>arr[n-1]) return n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<target) low=mid+1;
            else if(arr[mid]>target) {
                high=mid-1;
                up=mid;
            }
            else return mid;
        }
        return up;
    }
};
