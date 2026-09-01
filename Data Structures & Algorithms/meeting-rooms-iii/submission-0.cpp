class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> available;
        for(int room=0; room<n; room++){
            available.push(room);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        vector<int> count(n, 0);

        for(auto& meeting : meetings){
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end- start;
            while(!busy.empty() && busy.top().first <= start){
                int room = busy.top().second;
                available.push(room);
                busy.pop();
            }
            if(!available.empty()){
                int room = available.top();
                available.pop();
                busy.push({end, room});
                count[room]++;
            }else{
                auto [freeTime, room] = busy.top();
                busy.pop();
                long long newEnd = freeTime + duration;
                busy.push({newEnd, room});
                count[room]++;
            }
        }
        int answer = 0;
        for(int room=1; room<n; room++){
            if(count[room] > count[answer]){
                answer = room;
            }
        }
        return answer;
    }
};