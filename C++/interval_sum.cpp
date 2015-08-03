/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class SegmentTreeSumNode {
public:
    int start, end;
    long long sum;
    SegmentTreeSumNode *left, *right;
    SegmentTreeSumNode() {}
    SegmentTreeSumNode(int s, int e, long long t) : start(s), end(e), sum(t), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> result;
        
        SegmentTreeSumNode *root=build(A, 0, A.size()-1);
        
        for(const auto interval:queries) {
            result.push_back(query(root, interval.start, interval.end));
        }
        
        return result;
    }
    
    SegmentTreeSumNode *build(vector<int> &A, int start, int end) {
        if(start>end) return nullptr;
        
        SegmentTreeSumNode *root=new SegmentTreeSumNode(start, end, 0);
        if(start==end) {
            root->sum=A[start];
            return root;
        }
        
        root->left=build(A, start, (start+end)/2);
        root->right=build(A, (start+end)/2+1, end);
        
        long long left=root->left==nullptr?0:root->left->sum;
        long long right=root->right==nullptr?0:root->right->sum;
        
        root->sum=left+right;
        
        return root;
    }
    
    long long query(SegmentTreeSumNode *root, int start, int end) {
        if(root==nullptr || start>root->end || end<root->start) {
            return 0;
        }
        
        if(start<=root->start && root->end<=end) {
            return root->sum;
        }
        
        long long left=query(root->left, start, end);
        long long right=query(root->right, start, end);
        
        return left+right;
    }
};
