class DictionaryEntry {
public: 
    DictionaryEntry(char c) { this->letter = c; }
    DictionaryEntry() {}
    
    char letter;
    bool isLeaf = false;
    map<char, DictionaryEntry*> entries;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new DictionaryEntry();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        DictionaryEntry* r = root;
        for (int i=0; i<word.length(); i++) {
            if ((r->entries).find(word[i]) != (r->entries).end()) {
                r = (r->entries)[word[i]];
            } else {
                DictionaryEntry *tmp = new DictionaryEntry(word[i]);
                (r->entries)[word[i]] = tmp;
                r = tmp;
            }
        }
        r->isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return searchDictionaryEntry(word, 0, root);
    }
    
    bool searchDictionaryEntry(string word, int index, DictionaryEntry* root) {
        if (index == word.length() && root->isLeaf) {
            return true;
        } else if (index == word.length() ){
            return false;
        }
        
        if ((root->entries).find(word[index]) != (root->entries).end()) { // letter found.
            return searchDictionaryEntry(word, index+1, (root->entries)[word[index]]);
        } else if (word[index]=='.') { // wild card found.
            bool result = false;
            for (map<char, DictionaryEntry*>::iterator it=(root->entries).begin(); it!=(root->entries).end(); it++) {
                if (searchDictionaryEntry(word, index+1, it->second)) {
                    result = true;
                }
            }
            return result;
        } else { // null.
            return false;
        }
    }
    
private:
    DictionaryEntry* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
