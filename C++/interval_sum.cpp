/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class SegmentTreeMinNode {
public:
    int start, end, min;
    SegmentTreeMinNode *left, *right;
    SegmentTreeMinNode() {}
    SegmentTreeMinNode(int s, int e, int m) : start(s), end(e), min(m), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> result;
        
        SegmentTreeMinNode *root=build(A, 0, A.size()-1);
        
        for(const auto interval:queries) {
            result.push_back(query(A, root, interval.start, interval.end));
        }
        
        return result;
    }
    
    SegmentTreeMinNode *build(vector<int> &A, int start, int end) {
        if(start>end) return nullptr;
        
        SegmentTreeMinNode *root=new SegmentTreeMinNode(start, end, INT_MAX);
        
        if(start==end) {
            root->min=A[start];
            return root;
        }
        
        int mid=(start+end)/2;
        root->left=build(A, start, mid);
        root->right=build(A, mid+1, end);
        
        int left=root->left==nullptr?INT_MAX:root->left->min;
        int right=root->right==nullptr?INT_MAX:root->right->min;
        root->min=min(left, right);
        
        return root;
    }
    
    int query(vector<int> &A, SegmentTreeMinNode *root, int start, int end) {
        if(root==nullptr || start>root->end || end<root->start) {
            return INT_MAX;
        }
        
        if(start<=root->start && root->end<=end) {
            return root->min;
        }
        
        int left_min=query(A, root->left, start, end);
        int right_min=query(A, root->right, start, end);
        
        return min(left_min, right_min);
    }
};
