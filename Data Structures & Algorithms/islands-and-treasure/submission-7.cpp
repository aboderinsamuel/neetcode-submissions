class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>>q;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1,0}, {1,0},{0,-1}, {0, 1}};
        const int INF = 2147483647;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto& [dr, dc]: directions){
                int nextRow = dr+r;
                int nextCol = dc+c;
                if(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == INF){
                    grid[nextRow][nextCol] = grid[r][c] + 1;
                    q.push({nextRow,nextCol});
                }
            }
            
        }
    }
};
