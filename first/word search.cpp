class Solution {
public:
    bool existRecur(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word,
                    int current, int row, int col) {
        if (current == word.size()) return true;
        if (row-1 >= 0 && !visited[row-1][col] && board[row-1][col] == word[current]) {
            visited[row-1][col] = true;
            if (existRecur(board, visited, word, current+1, row-1, col)) {
                return true;
            }
            visited[row-1][col] = false;
        }
        if (row+1 < board.size() && !visited[row+1][col] && board[row+1][col] == word[current]) {
            visited[row+1][col] = true;
            if (existRecur(board, visited, word, current+1, row+1, col)) {
                return true;
            }
            visited[row+1][col] = false;
        }
        if (col-1 >= 0 && !visited[row][col-1] && board[row][col-1] == word[current]) {
            visited[row][col-1] = true;
            if (existRecur(board, visited, word, current+1, row, col-1)) {
                return true;
            }
            visited[row][col-1] = false;
        }
        if (col+1 < board[0].size() && !visited[row][col+1] && board[row][col+1] == word[current]) {
            visited[row][col+1] = true;
            if (existRecur(board, visited, word, current+1, row, col+1)) {
                return true;
            }
            visited[row][col+1] = false;
        }
        return false;
    }


    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) return false;
        if (word.size() == 0) return true;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (existRecur(board, visited, word, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};