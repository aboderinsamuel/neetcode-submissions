class Solution {
private:
    int findRoot(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent, parent[x]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        int totalCost = 0;
        int edgesConnected = 0;

        for(auto& edge: edges){
            int dist = edge[0];
            int u = edge[1];
            int v = edge[2];

            int rootU = findRoot(parent, u);
            int rootV = findRoot(parent, v);

            if(rootU != rootV){
                parent[rootU] = rootV;
                totalCost += dist;
                edgesConnected++;
                if(edgesConnected == n-1) break;
            }
        }
        return totalCost;
    }
};
