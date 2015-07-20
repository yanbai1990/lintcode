class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        const int rows=matrix.size();
        const int cols=matrix[0].size();
        vector<vector<int> > f(rows, vector<int>(cols, 0));
        int maxsize=0;
        
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(i==0 || j==0) {
                    f[i][j]=matrix[i][j];
                } else if(matrix[i][j]==0){
                    f[i][j]=0;
                } else if(matrix[i][j]==1){
                    f[i][j]=min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1])+1;
                }
                maxsize=max(maxsize,f[i][j]);
            }
        }
        
        return maxsize*maxsize;
    }
};
