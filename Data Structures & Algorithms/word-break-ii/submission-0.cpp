class Solution {
private:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(const string& s, int start){
        if(start == s.size()){
            return {""};
        }
        if(memo.count(start)){
            return memo[start];
        }
        vector<string> result;
        for(int end=start+1; end<=s.size(); end++){
            string word = s.substr(start, end-start);
            if(!dict.count(word)) continue;
            vector<string> suffixes = dfs(s, end);
            for(string& suffix : suffixes){
                if(suffix.empty()){
                    result.push_back(word);
                }else{
                    result.push_back(word + " " + suffix);
                }
            }
        }
        return memo[start] = result;

    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(const string& word : wordDict){
            dict.insert(word);
        }
        return dfs(s, 0);
    }
};