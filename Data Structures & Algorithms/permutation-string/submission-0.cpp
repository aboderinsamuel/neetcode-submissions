class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int windowLen = s1.size();
        vector<int> window(26, 0);
        vector<int> need(26,0);
        int left = 0;

        for(char c : s1){
            need[c - 'a']++;
        }
        for(int right=0; right < s2.size(); right++){
            window[s2[right] - 'a']++;
            if((right-left+1) > windowLen){
                window[s2[left] - 'a']--;
                left++;
            }
            if(window == need){
                return true;
            }
        }
        return false;
    }
};
