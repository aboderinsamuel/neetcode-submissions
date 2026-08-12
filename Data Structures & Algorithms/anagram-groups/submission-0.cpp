class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        for(auto& groups : mp){
            result.push_back(groups.second);
        }
        return result;
    }
};
