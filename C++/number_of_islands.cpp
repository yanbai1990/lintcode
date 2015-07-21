class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here
        if(grid.empty()) return 0;
        const size_t m=grid.size();
        const size_t n=grid[0].size();
        int num_of_lands=0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        
        for(size_t i=0; i<m; ++i) {
            for(size_t j=0; j<n; ++j) {
                if(grid[i][j] && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    ++num_of_lands;
                }
            }
        }
        return num_of_lands;
    }
    
    void dfs(vector<vector<bool> > &grid, vector<vector<bool> > &visited, size_t row, size_t col) {
        if(grid[row][col]==0 || visited[row][col]) return;
        visited[row][col]=true;
        if(row>0){
            dfs(grid, visited, row-1, col);
        }
        if(row<grid.size()-1) {
            dfs(grid, visited, row+1, col);
        }
        if(col>0) {
            dfs(grid, visited, row, col-1);
        }
        if(col<grid[0].size()-1) {
            dfs(grid, visited, row, col+1);
        }
    }
};
