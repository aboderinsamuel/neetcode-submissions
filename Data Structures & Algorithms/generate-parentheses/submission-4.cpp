class Solution {
public:
    void dfs(vector<string>& result, string current, int open, int close, int n){
        if(current.size() == 2*n){
            result.push_back(current);
            return;
        }
        if(open < n){
            dfs(result, current+'(', open+1, close, n);
        }
        if(close < open){
            dfs(result, current+')', open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, "", 0, 0, n);
        return result;
    }
};
