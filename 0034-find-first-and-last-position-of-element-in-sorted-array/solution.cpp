class Solution {
    private:
    int fst(vector<int>& arr,int n, int target){
        int low=0;
        int high=n-1;
        int fst=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<target) low=mid+1;
            else if(arr[mid]>target) high=mid-1;
            else {
            fst=mid;
            high=mid-1;
            }
        }
        return fst;
    }
    int lst(vector<int>& arr,int n, int target){
        int low=0;
        int high=n-1;
        int lst=-1;
        while(low<=high){
           int mid=(low+high)/2;
            if(arr[mid]<target) low=mid+1;
            else if(arr[mid]>target) high=mid-1;
            else {
            lst=mid;
            low=mid+1; 
            }
        }
        return lst;
    }
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        return {fst(arr,n,target),lst(arr,n,target)};
    }
};
