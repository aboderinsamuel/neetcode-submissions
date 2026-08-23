class Solution {
private:
    int find(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        iota(parent.begin(), parent.end(), 0);

        for(auto& edge : edges){
            int rootX = find(parent, edge[0]);
            int rootY = find(parent, edge[1]);

            if(rootX == rootY){
                return edge;
            }
            parent[rootX] = rootY;
        }
        return {};
    }
};
