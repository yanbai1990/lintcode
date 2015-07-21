class Solution {
public:
    /**
     * @param board: the board
     * @return: wether the Sudoku is valid
     */
    bool isValidSudoku(const vector<vector<char>>& board) {
        unordered_set<char> used;
        const int n=board.size();
        for(int i=0; i<n; ++i) {
            used.clear();
            for(int j=0; j<n; ++j) {
                if(board[i][j]=='.') continue;
                if(!used.insert(board[i][j]).second)
                    return false;
            }
        }
        
        for(int j=0; j<n; ++j) {
            used.clear();
            for(int i=0; i<n; ++i) {
                if(board[i][j]=='.') continue;
                if(!used.insert(board[i][j]).second)
                    return false;
            }
        }
        
        for(int r=0; r<n/3; ++r) {
            for(int c=0; c<n/3; ++c) {
                used.clear();
                for(int i=r*3; i<r*3+3; ++i) {
                    for(int j=c*3; j<c*3+3; ++j) {
                        if(board[i][j]=='.') continue;
                        if(!used.insert(board[i][j]).second)
                            return false;
                    }
                }
            }
        }
        
        return true;
    }
};
