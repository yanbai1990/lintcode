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
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string output;
        serialize(root, output);
        return output;
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        TreeNode *root=NULL;
        int start=0;
        deserialize(data, root, start);
        return root;
    }
    
private:
    void serialize(TreeNode *root, string &output) {
        if(!root) output+="# ";
        else {
            stringstream ss;
            ss<<(root->val)<<" ";
            output+=ss.str();
            serialize(root->left, output);
            serialize(root->right, output);
        }
    }
    
    void deserialize(string data, TreeNode *&root, int &start) {
        int num;
        if(get(data, start, num)) {
            root=new TreeNode(num);
            deserialize(data, root->left, start);
            deserialize(data, root->right, start);
            return;
        }
        root=NULL;
        return;
    }
    
    bool get(string data, int &start, int &num) {
        if(data[start]=='#') {
            start+=2;
            return false;
        }
        num=0;
        while(data[start]!=' ') {
            num=num*10+data[start++]-'0';
        }
        ++start;
        return true;
    }
    
};

