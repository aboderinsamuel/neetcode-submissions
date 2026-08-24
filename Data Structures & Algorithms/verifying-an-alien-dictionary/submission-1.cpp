class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alienOrder[26];
        for(int i=0; i<26; i++){
            alienOrder[order[i] - 'a'] = i;
        }
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            bool differenceFound = false;
            int minLen = min(w1.length(), w2.length());
            for(int j=0; j<minLen; j++){
                if(w1[j] != w2[j]){
                    if(alienOrder[w1[j] - 'a'] > alienOrder[w2[j] - 'a']){
                        return false;
                    }
                    differenceFound = true;
                    break;
                }
            }
            if(!differenceFound && w1.length() > w2.length()){
                return false;
            }
        }
        return true;
    }
};