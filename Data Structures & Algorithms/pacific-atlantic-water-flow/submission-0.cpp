class Solution {
private:
    vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int rows, cols;
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        visited[r][c] = true;
        for(auto& [dr, dc] : directions){
            int newR = r+dr;
            int newC = c+dc;
            if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && !visited[newR][newC]){
                if(heights[newR][newC] >= heights[r][c]){
                    dfs(newR, newC, visited, heights);
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for(int r=0; r<rows; r++){
            dfs(r, 0, pacific, heights);
            dfs(r, cols-1, atlantic, heights);
        }
        for(int c=0; c<cols; c++){
            dfs(0, c, pacific, heights);
            dfs(rows-1, c, atlantic, heights);
        }
        vector<vector<int>> result;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};
