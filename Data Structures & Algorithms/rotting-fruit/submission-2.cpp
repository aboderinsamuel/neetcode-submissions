class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>>q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols;c ++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }else if(grid[r][c] == 1){
                    freshCount++;
                }
            }
        }
        int minutes = 0;
        if(freshCount == 0) return 0;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            bool rottedSomething = false;
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto& [dr, dc] : directions){
                    int newR = r+ dr;
                    int newC = c + dc;

                    if(newR < 0 || newR >= rows || newC < 0 || newC >= cols) continue;
                    if(grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        freshCount--;
                        q.push({newR, newC});
                        rottedSomething = true;
                    }
                }
            }
            if(rottedSomething){
                minutes++;
            }
        }
        if(freshCount > 0) return -1;
        return minutes;

        
    }
};
