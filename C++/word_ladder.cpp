class Solution {
public:
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return an integer
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        int length=1;
        queue<string> visited;
        
        visited.push(start);
        dict.erase(start);
        
        while(!visited.empty()) {
            int count=visited.size();
            for(int i=0; i<count; ++i) {
                string word=visited.front();
                visited.pop();
                for(char &letter:word) {
                    for(int i=0; i<26; ++i) {
                        char tmp=letter;
                        if(letter=='a'+i) {
                            continue;
                        }
                        letter='a'+i;
                        if(word==end) return length+1;
                        if(dict.find(word)!=dict.end()) {
                            visited.push(word);
                            dict.erase(word);
                        }
                        letter=tmp;
                    }
                }
            }
            ++length;
        }
        return 0;
    }
};
