class Solution1 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return false;
        int start=0;
        int end=matrix.size()-1;
        int row, column;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(matrix[mid][0]==target) {
                return true;
            } else if(matrix[mid][0]<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(target>matrix[end][0]) row=end;
        else row=start;
        
        start=0;
        end=matrix[row].size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(matrix[row][start]==target) return true;
        else if(matrix[row][end]==target) return true;
        return false;
    }
};

class Solution2 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return false;
        const int rows=matrix.size();
        const int cols=matrix[0].size();
        int start=0;
        int end=rows*cols-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            int elmt=matrix[mid/cols][mid%cols];
            if(elmt==target)
                return true;
            else if(elmt<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(matrix[start/cols][start%cols]==target) return true;
        else if(matrix[end/cols][end%cols]==target) return true;
        else return false;
    }
};



