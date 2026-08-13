class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] == '.') continue;
                char num = board[r][c];
                int box = (r/3)*3 + c/3;

                string colKey = "C" + to_string(r) + "_" + num;
                string boxKey = "B" + to_string(c) + "_" + num;
                string rowKey = "R" + to_string(box) + "_" + num;

                if(seen.count(colKey) || seen.count(rowKey) || seen.count(boxKey)) return false;
                seen.insert(colKey);
                seen.insert(boxKey);
                seen.insert(rowKey);
            }
        }
        return true;
    }
};
