class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n+1, 0);
        for(auto& relations : trust){
            int truster = relations[0];
            int trustee = relations[1];

            trustScore[truster]--;
            trustScore[trustee]++;
        }
        for(int i=1; i<=n; i++){
            if(trustScore[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};