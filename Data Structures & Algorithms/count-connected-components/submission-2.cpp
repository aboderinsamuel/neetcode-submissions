class Solution {
private:
    int find(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int components = n;

        for(auto& edge : edges){
            int rootX = find(parent, edge[0]);
            int rootY = find(parent, edge[1]);

            if(rootX != rootY){
                parent[rootX] = rootY; //unconditional merge
                components--; //decrement on the fly
            }
        }
        return components;
    }
};
