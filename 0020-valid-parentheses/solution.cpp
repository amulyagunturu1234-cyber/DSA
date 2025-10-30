class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ch=st.top();
                
                if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{')) {
                    st.pop();
                }else{
                    return false;
                } 
            }
        }
     return st.empty();   
    }
};
