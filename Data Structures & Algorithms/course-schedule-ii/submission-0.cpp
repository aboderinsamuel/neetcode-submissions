class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& p : prerequisites){
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            ++indegree[course];
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> order; //instead of int taken = 0;
        order.reserve(numCourses);

        while(!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);

            for(int next : adj[course]){
                if(--indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return order.size() == numCourses ? order : vector<int>{};

    }
};
