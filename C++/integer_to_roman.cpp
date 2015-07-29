class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        map<int, string, greater<int> > map={{1, "I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400, "CD"}, {500,"D"}, {900,"CM"}, {1000, "M"}};
        
        string result;
        for(const auto pair:map) {
            while(n>=pair.first) {
                n-=pair.first;
                result.append(pair.second);
            }
        }
        
        return result;
    }
};
