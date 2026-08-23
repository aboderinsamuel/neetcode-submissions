class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //create a 2D reachability table initialized to false
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));

        //step 1 : Map all direct prerequisites
        for(auto& pre : prerequisites){
            isPre[pre[0]][pre[1]] = true;
        }
        //step 2 : floy-warshall to discover indirect prerequisites
        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    if(isPre[i][k] && isPre[k][j]){
                        isPre[i][j] = true;
                    }
                }
            }
        }
        vector<bool> result;
        for(auto& q : queries){
            result.push_back(isPre[q[0]][q[1]]);
        }
        return result;
    }
};