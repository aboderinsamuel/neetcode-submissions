class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i], (char)(i + 'a')});
            }
        }
        string result = "";
        while(maxHeap.size() > 1){
            auto first = maxHeap.top();
            maxHeap.pop();
            auto second = maxHeap.top();
            maxHeap.pop();
            result += first.second;
            result += second.second;

            if(--first.first > 0){
                maxHeap.push(first);
            }
            if(--second.first > 0){
                maxHeap.push(second);
            }
        }
        if(!maxHeap.empty()){
            auto last = maxHeap.top();
            if(last.first > 1){
                return "";
            }
            result += last.second;
        }
        return result;
    }
};