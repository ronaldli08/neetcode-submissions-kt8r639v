class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //vertical
        for(int i = 0; i < 9; ++i) {
            vector<int> counter(10, 0);
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] != '.') {
                    if(counter[board[j][i]-'0']++ == 1) {
                        return false;
                    }
                }
            }
        }

        //horizontal
        for(int i = 0; i < 9; ++i) {
            vector<int> counter(10, 0);
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    if(counter[board[i][j]-'0']++ == 1) {
                        return false;
                    }
                }
            }
        }

        //box
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                vector<int> counter(10, 0);
                for(int row = 0; row < 3; ++row) {
                    for(int col = 0; col < 3; ++col) {
                    if(board[i*3 + row][j*3+col] != '.') {
                        if(counter[board[i*3 + row][j*3+col]-'0']++ == 1) {
                            return false;
                        }
                    }
                    }
                }
            }
            
        }
        return true;
    }
};
