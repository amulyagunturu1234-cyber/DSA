class Solution {
    private:
    int f(vector<int> &arr,int n,int target){
        int low=0;
        int high=n-1;
        while(low<=high){
               int mid=low+((high-low)/2);
                if(arr[mid]==target) return mid;
                //left sorted
                if(arr[low]<=arr[mid]){
                    if(arr[low]<=target && target<=arr[mid]){
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                //right soreted
                else{
                    if(arr[mid]<=target && target<=arr[high]){
                        low=mid+1;
                    }
                    else high=mid-1;
                }
        }
        return -1;
    }
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        return f(arr,n,target);
    }
};
