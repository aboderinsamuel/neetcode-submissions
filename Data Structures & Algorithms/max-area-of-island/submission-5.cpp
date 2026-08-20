class Solution {
    vector<pair<int, int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return 0;
        if(grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        int best = 1;
        for(auto& [dr, dc] : directions){
            best += dfs(grid, row+dr, col+dc);
        }
        return best;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int best = 0;
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 1){
                    best = max(best, dfs(grid, row, col));
                }
            }
        }
        return best;
    }
};
