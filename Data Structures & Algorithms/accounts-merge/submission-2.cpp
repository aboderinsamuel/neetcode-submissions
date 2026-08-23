class Solution {
private:
    int find(vector<int>& parent, int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        //1 
        unordered_map<string, int> emailToId;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(emailToId.count(email)){
                    int rootX = find(parent, i);
                    int rootY = find(parent, emailToId[email]);
                    if(rootX != rootY){
                        parent[rootX] = rootY;
                    }
                }else{
                    emailToId[email] = i;
                }
            }
        }

        //2
        unordered_map<int, vector<string>> mergedComponents;
        for(auto& [email, accId] : emailToId){
            int rootAccId = find(parent, accId);
            mergedComponents[rootAccId].push_back(email);
        }
        //3
        vector<vector<string>> result;
        for(auto& [rootId, emails] : mergedComponents){
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(accounts[rootId][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        return result;
    }
};