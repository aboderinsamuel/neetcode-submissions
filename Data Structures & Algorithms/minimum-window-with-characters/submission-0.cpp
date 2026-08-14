class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        vector<int> need(128, 0);

        for(char c : t){
            need[c]++;
        }
        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        int required = t.length();

        for(int right=0; right<s.length(); right++){
            char c = s[right];
            if(need[c] > 0){
                required--;
            }
            need[c]--;

            while(required == 0){
                int curr_len = right-left+1;
                if(curr_len < min_len){
                    min_len = curr_len;
                    min_start = left;
                }
                //shrink from left
                char left_char = s[left];
                need[left_char]++;
                if(need[left_char] > 0){
                    required++;
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
