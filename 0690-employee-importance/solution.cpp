/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
unordered_map<int, Employee*> mp;
    int solve(int id){
                   int ans=0;
                   Employee* emp=mp[id];
                   //basically we stored the id in a map in a correct position 
                   //so that we can acccess it easily
                   ans+=emp->importance;
                   for(auto it:emp->subordinates){
                    ans+=solve(it);
                   }
                   return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //we need to return the sum importance of parent and its adj nodes as well 
        int n=employees.size();
        for(auto e: employees){
            mp[e->id]= e;
        }
        return solve(id);
    }
};
