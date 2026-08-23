class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //base case: if there are 1 or 2 nodes, they are all valid roots
        if(n <= 2){
            vector<int> result;
            for(int i=0; i<n; i++){
                result.push_back(i);
            }
            return result;
        }
        //step1 : build adjacency list and track in-degrees
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        //step 2: initialize queue with all nitial leaf nodes
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        int remainingNodes = n;
        while(remainingNodes > 2){
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for(int i=0; i<leafCount; i++){
                int leaf = q.front();
                q.pop();
                for(int neighbor : adj[leaf]){
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};