class Solution {
private:
    double dfs(string current, string target, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>>& adj){
        if(current == target) return 1.0;
        visited.insert(current);
        for(auto& neighborPair : adj[current]){
            string neighbor  = neighborPair.first;
            double weight = neighborPair.second;
            if(!visited.count(neighbor)){
                double result = dfs(neighbor, target, visited, adj);
                if(result != -1.0){
                    return weight*result;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }
        vector<double> results;
        for(auto& query : queries){
            string src = query[0];
            string dest = query[1];
            if(!adj.count(src) || !adj.count(dest)){
                results.push_back(-1.0);
            }else{
                unordered_set<string> visited;
                results.push_back(dfs(src, dest, visited, adj));
            }
        }
        return results;
    }
};