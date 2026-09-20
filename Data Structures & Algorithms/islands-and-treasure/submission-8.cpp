class Solution {
public:
    vector<pair<int, int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto& [dr, dc] : directions){
                int newR = r + dr;
                int newC = c + dc;
                if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] ==INF){
                    grid[newR][newC] = grid[r][c] + 1;
                    q.push({newR, newC});                }
            }
        }
    }
};
