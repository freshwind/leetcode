class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        N = sqrt(board.size());
        found = false;
        dfs(board, 0, 0);
    }
private:
    int N;
    bool found;
    void dfs(vector<vector<char> > &board, int i, int j) {
        if (found) return;
        if (i == N*N) {
            found = true;
            return;
        }
        if (j == N*N) {
            dfs(board,i+1,0);
            return;
        }
        if (board[i][j] == '.') {
            vector<bool> checks(N*N+1, true);
            for (int t = 0; t < N*N; ++t) {
                if (board[t][j] != '.') {
                    checks[board[t][j]-'0'] = false;
                }
                if (board[i][t] != '.') {
                    checks[board[i][t]-'0'] = false;
                }
            }
            int s = (i/N)*N;
            int t = (j/N)*N;
            for (int ii = 0; ii < N; ++ii) {
                for (int jj = 0; jj < N; ++jj) {
                    if (board[s+ii][t+jj] != '.') {
                        checks[board[s+ii][t+jj]-'0'] = false;
                    }
                }
            }
            for (int ii = 1; ii <= N*N && !found; ++ii) {
                if (checks[ii]) {
                    board[i][j] = ii+'0';
                    dfs(board, i, j+1);
                }
            }
            if (!found)
                board[i][j] = '.';
        } else {
            dfs(board,i, j+1);
        }
    }
};

