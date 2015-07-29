//TLE
class Solution1 {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> result;
        for(const int query:queries) {
            int count=0;
            for(const int i:A) {
                if(i<query) {
                    ++count;
                }
            }
            result.emplace_back(count);
            count=0;
        }
        return result;
    }
};

//Sort and binary search
class Solution2 {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        if(A.empty()) {
            vector<int> result(queries.size(), 0);
            return result;
        }
        
        vector<int> result;
        sort(A.begin(), A.end());
        for(const int i:queries) {
            auto it=lower_bound(A.cbegin(), A.cend(), i);
            result.emplace_back(it-A.cbegin());
        }
        
        return result;
    }
};

/*class SegmentTreeNode {
 public:
 int start, end, count;
 SegmentTreeNode *left, *right;
 SegmentTreeNode(int start, int end, int count) {
 this->start = start;
 this->end = end;
 this->count = count;
 this->left = this->right = NULL;
 }
 }*/

class Solution3 {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> result;
        
        sort(A.begin(), A.end());
        
        SegmentTreeNode *root=build(0, A.size()-1);
        
        for(const int i:queries) {
            result.emplace_back(query(A, i, root, 0, A.size()-1));
        }
        
        return result;
    }
    
    SegmentTreeNode *build(int start, int end) {
        if(start>end) return nullptr;
        
        SegmentTreeNode *root=new SegmentTreeNode(start, end, 0);
        
        if(start==end) {
            root->count=1;
            return root;
        }
        
        int mid=(start+end)/2;
        root->left=build(start, mid);
        root->right=build(mid+1, end);
        
        int left_count=root->left==nullptr?0:root->left->count;
        int right_count=root->right==nullptr?0:root->right->count;
        
        root->count=left_count+right_count;
        
        return root;
    }
    
    int query(vector<int> &A, int q, SegmentTreeNode *root, int start, int end) {
        if(root==nullptr || start>root->end || end<root->start) {
            return 0;
        }
        
        if(q<=A[root->start]) return 0;
        if(q>A[root->end]) return root->count;
        
        int left=query(A, q, root->left, start, end);
        int right=query(A, q, root->right, start, end);
        
        return left+right;
    }
    
};






