class Solution {
private:
    vector<vector<string>> result;
    vector<string> board;
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void backtrack(int row, int n){
        if(row == n){
            result.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row-col);
            diag2.insert(row+col);
            backtrack(row+1, n);

            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row-col);
            diag2.erase(row+col);



        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(0, n);
        return result;
    }
};
