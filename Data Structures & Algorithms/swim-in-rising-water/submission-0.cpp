class Solution {
public:
    vector<pair<int, int>> directions = {{0,1}, {-1,0}, {1,0}, {0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        minTime[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0} });

        while(!pq.empty()){
            auto [time, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;

            if(row == n-1 && col == n-1) return time;
            if(time > minTime[row][col]) continue;
            for(auto [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if(nr < 0 || nr >= n || nc < 0 ||nc >=n) continue;
                int newTime = max(time, grid[nr][nc]);
                if(newTime < minTime[nr][nc]){
                    minTime[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
