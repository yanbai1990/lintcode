/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution1 {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> cur, next;
        vector<int> level;
        bool isLeftToRight=true;
        cur.push(root);
        while(!cur.empty()) {
            while(!cur.empty()) {
                auto node=cur.front();
                cur.pop();
                level.push_back(node->val);
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            
            if(!isLeftToRight) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            
            isLeftToRight=!isLeftToRight;
            level.clear();
            swap(cur, next);
        }
        return res;
    }
};

class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // write your code here
        int cur_level_length=1;
        bool isLeftToRight=true;
        vector<vector<int> > res;
        vector<int> level;
        queue<TreeNode*> cur;
        
        if(!root) return res;
        cur.push(root);
        
        while(!cur.empty()) {
            auto node=cur.front();
            cur.pop();
            --cur_level_length;
            
            level.push_back(node->val);
            if(node->left) cur.push(node->left);
            if(node->right) cur.push(node->right);
            
            if(cur_level_length==0) {
                if(!isLeftToRight) {
                    reverse(level.begin(), level.end());
                }
                res.push_back(move(level));
                cur_level_length=cur.size();
                isLeftToRight=!isLeftToRight;
            }
        }
        
        return res;
    }
};

