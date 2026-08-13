class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string str : strs){
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#')j++;
            int length = stoi(s.substr(i, j-i));
            j++;
            result.push_back(s.substr(j, length));
            i = j + length;
        }
        return result;
    }
};
