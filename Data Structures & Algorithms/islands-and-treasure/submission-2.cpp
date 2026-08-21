class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        //push all gates to a queue to start multi-source bfs
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }
        // now we move
        vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        const int INF = 2147483647;
        //process the grid layer by layer
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto& [dr, dc] : directions){
                int nextRow = r + dr;
                int nextCol = c + dc;
                if(nextCol >= 0 && nextCol < cols && nextRow >= 0 && nextRow < rows && grid[nextRow][nextCol] == INF){
                    grid[nextRow][nextCol] = grid[r][c] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }

    }
};
