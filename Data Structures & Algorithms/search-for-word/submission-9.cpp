class Solution {
private:
    int rows, cols;
    bool dfs(int r, int c, int index, vector<vector<char>>& board, const string& word){
        if(index == word.size()){
            return true;
        }
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(r+1,c, index+1, board, word) || dfs(r-1,c, index+1, board, word) || dfs(r,c+1, index+1, board, word) || dfs(r,c-1, index+1, board, word);
        board[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c] == word[0] && dfs(r, c, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
