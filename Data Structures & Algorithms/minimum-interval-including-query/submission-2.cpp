class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<pair<int, int>> sortedQueries;
        for(int i=0; i<queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(queries.size(), -1);

        int intervalPtr = 0;
        for(auto [query, index] : sortedQueries){
            while(intervalPtr < intervals.size() && intervals[intervalPtr][0] <= query){
                int start = intervals[intervalPtr][0];
                int end = intervals[intervalPtr][1];
                int size = end - start + 1;
                pq.push({size, end});
                intervalPtr++;
            }
            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }
            if(!pq.empty()){
                ans[index] = pq.top().first;
            }
        }
        return ans;
    }
};
