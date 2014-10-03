class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int N = sqrt(board.size());
        vector<bool> check(N*N, true);
        //row
        for (int i = 0; i < N*N; ++i) {
            for (int j = 0; j < N*N; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (check[board[i][j]-'1']) {
                    check[board[i][j]-'1'] = false;
                } else {
                    return false;
                }
            }
            for (int j = 0; j < N*N; ++j) {
                check[j] = true;
            }
        }
        //col
        for (int i = 0; i < N*N; ++i) {
            for (int j = 0; j < N*N; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (check[board[j][i]-'1']) {
                    check[board[j][i]-'1'] = false;
                } else {
                    return false;
                }
            }
            for (int j = 0; j < N*N; ++j) {
                check[j] = true;
            }
        }
        //cube
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int s = 0; s < N; ++s) {
                    for (int t = 0; t < N; ++t) {
                        if (board[i*3+s][j*3+t] == '.') {
                            continue;
                        }
                        if (check[board[i*3+s][j*3+t]-'1']) {
                            check[board[i*3+s][j*3+t]-'1'] = false;
                        } else {
                            return false;
                        }
                    }
                }
                for (int s = 0; s < N*N; ++s) {
                    check[s] = true;
                }
            }
        }
        return true;
    }
};
