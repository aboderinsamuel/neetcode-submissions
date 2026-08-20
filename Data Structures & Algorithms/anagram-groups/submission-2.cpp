class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> myMap;

        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            myMap[key].push_back(s);
        }
        for(auto& groups : myMap){
            result.push_back(groups.second);
        }
        return result;
    }
};
