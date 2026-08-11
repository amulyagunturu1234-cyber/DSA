class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int rec=recipes.size();
        int ing=ingredients.size();
        int supp=supplies.size();
        //how to know which recipe needs the particular ingredient
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
         for(int i = 0; i < rec; i++) {
            indegree[recipes[i]] = ingredients[i].size();//like storing the indegree like bread neads yeast and flour so 2
            for(auto ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);// this ingredient is used in these many recipes
            }
        }
        queue<string> q;
        for(auto s : supplies) {
        q.push(s);//to check the supplies
        }
        vector<string> ans;
        while(!q.empty()){
            string item=q.front();
            q.pop();
            for(auto recipe : graph[item]) {
                 indegree[recipe]--;
                 if(indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);
                 }
        }
    }
    return ans;
    }
};