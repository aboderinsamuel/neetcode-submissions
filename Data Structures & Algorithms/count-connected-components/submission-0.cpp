class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        int components = n;

        auto find = [&](auto& self, int x) -> int {
            if(parent[x] != x){
                parent[x] = self(self, parent[x]);
                //path compression
            }
            return parent[x];
        };
        for(auto& edge : edges){
            int rootX = find(find, edge[0]);
            int rootY = find(find, edge[1]);

            if(rootX != rootY){
                parent[rootX] = rootY; //unconditional merge
                components--; //decrement on the fly
            }
        }
        return components;
    }
};
