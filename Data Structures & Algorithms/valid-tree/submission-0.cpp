class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //condition 1 : A tree must have exactly n-1 edges
        if(edges.size() != n-1) return false;

        //build adjacency list from undirected graph
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        queue<int> q;

        q.push(0);
        visited.insert(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor : adj[node]){
                //if neighbor is not visited, mark it and queue it up
                if(!visited.count(neighbor)){
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        //condition 2 : the graph must be fully connected
        return visited.size() == n;
    }
};
