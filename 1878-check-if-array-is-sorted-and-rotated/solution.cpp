class Solution {
public:
    bool check(vector<int>& arr) {
        int n=arr.size();
          int cnt=0;
       for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            cnt++;
        }
        if(cnt>1) return false;
    }
    return true;
    }
};
