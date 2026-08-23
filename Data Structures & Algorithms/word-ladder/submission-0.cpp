class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //step 1 : put all words into a hsashset for O(1) lookups and visited track
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //base case: if the destination word isnt even in the list, a transformation is impossible
        if(!wordSet.count(endWord)) return 0;
        //step2: set up BFS queue
        queue<string> q;
        q.push(beginWord);

        int changes = 1;
        //starting length

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();
                if(word == endWord) return changes;
                for(int pos=0; pos<word.length(); pos++){
                    char originalChar = word[pos];
                    for(char c = 'a'; c<= 'z'; c++){
                        if(c == originalChar) continue;
                        word[pos] = c;
                        if(wordSet.count(word)){
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[pos] = originalChar;
                }
            }
            changes++;
        }
        return 0;
    }
};
