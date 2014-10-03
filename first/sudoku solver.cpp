class Solution {
public:
    bool indexPlus(int &i, int &j, const int &N) {
        // cout <<i <<"," <<j <<"," <<N <<endl;
        j++;
        if (j == N*N) {
            i++;
            if (i == N*N) {
                return false;
            }
            j = 0;
        }
        return true;
    }

    bool solveSudokuRecur(vector<vector<char> > &board,
                          int i, int j,
                          const int &N) {
        do {
            // cout <<i <<"," <<j <<"," <<N <<endl;
            if (board[i][j] == '.') {
                vector<int> hash(N*N+1, 0);
                // print(hash);
                int temp;
                for (int s = 0; s < N*N; s++) {
                    if (board[s][j] != '.') {
                        temp = board[s][j] - '0';
                        // cout <<temp <<endl;
                        // if (hash[temp] == 1) return false;
                        hash[temp] = 1;
                    }
                    if (board[i][s] != '.') {
                        temp = board[i][s] - '0';
                        // cout <<temp <<endl;
                        // if (hash[temp] == 1) return false;
                        hash[temp] = 1;
                    }
                }
                // print(hash);
                for (int s = 0; s < N; s++) {
                    for (int t = 0; t < N; t++) {
                        if (board[i/N*N + s][j/N*N + t] != '.') {
                            temp = board[i/N*N + s][j/N*N + t] - '0';
                            // if (hash[temp] == 1) return false;
                            hash[temp] = 1;
                        }
                    }
                }
                // print(hash);
                for (int s = 1; s <= N*N; s++) {
                    if (hash[s] != 1) {
                        board[i][j] = '0' + s;
                        // print(board);
                        if (solveSudokuRecur(board, i, j, N)) {
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }
        } while(indexPlus(i, j, N));
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        int size = board.size();
        int N = sqrt(size);
        // cout<<N;
        solveSudokuRecur(board, 0, 0, N);
    }
};