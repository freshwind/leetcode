class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        row = board.size();
        col = board[0].size();
        hitmap.assign(row, vector<bool>(col, true));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int row;
    int col;
    vector<vector<bool> > hitmap;
    bool dfs(vector<vector<char> > &board, string &word, int i, int j, int curr) {
        if (curr == word.size()) {
            return true;
        }
        if (i < row && i >=0 && j < col && j >= 0 && hitmap[i][j] && board[i][j]==word[curr]) {
            hitmap[i][j] = false;
            if (dfs(board, word, i+1, j, curr+1)) return true;
            if (dfs(board, word, i, j+1, curr+1)) return true;
            if (dfs(board, word, i-1, j, curr+1)) return true;
            if (dfs(board, word, i, j-1, curr+1)) return true;
            hitmap[i][j] = true;
        }
        return false;
    }
};
