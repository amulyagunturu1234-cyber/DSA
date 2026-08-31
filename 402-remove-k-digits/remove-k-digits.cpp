class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        int n=num.size();
        string st="";
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.back()>num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        //removing eading zeros
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
        if(st==""){
            return "0";
        }
        return st; 
    }
};