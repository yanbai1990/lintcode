/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c) { this->letter = c; }
    TrieNode() {}
    
    bool isLeaf = false;
    char letter;
    map<char, TrieNode*> nodes;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *r = root;
        for (int i=0; i<word.length(); i++) {
            if ((r->nodes).find(word[i]) != (r->nodes).end()) {
                r = (r->nodes)[word[i]];
            } else {
                TrieNode *tmp = new TrieNode(word[i]);
                (r->nodes)[word[i]] = tmp;
                r = tmp;
            }
            if (i==word.length()-1) {
                r->isLeaf = true;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *leaf = searchWordNode(word);
        if (leaf == NULL) {
            return false;
        } else if (leaf->isLeaf) {
            return true;
        } else {
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) {
        TrieNode *leaf = searchWordNode(word);
        if (leaf == NULL) {
            return false;
        } else {
            return true;
        }
    }
    
    TrieNode* searchWordNode(string word) {
        TrieNode *leaf = NULL;
        map<char, TrieNode*> nodes = root->nodes;
        for (int i=0; i<word.length(); i++) {
            if(nodes.find(word[i]) != nodes.end()) {
                leaf = nodes[word[i]];
                nodes = nodes[word[i]]->nodes;
            } else {
                return NULL;
            }
        }
        return leaf;
    }

private:
    TrieNode* root;
};
