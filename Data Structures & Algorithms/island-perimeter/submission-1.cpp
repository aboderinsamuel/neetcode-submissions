class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        vector<pair<int, int>>  directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1){
                    for(auto& [dr, dc] : directions){
                        int nr = r+dr;
                        int nc = c+dc;
                        if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == 0){
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};