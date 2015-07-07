class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        size_t pos=n.find(".");
        int integer_part=stoi(n.substr(0,pos));
        double fractional_part=stod(n.substr(pos));
        string integer_str="";
        string fractional_str="";
        
        if(integer_part==0) integer_str="0";
        while(0<integer_part) {
            if(integer_part%2==1) {
                integer_str.insert(integer_str.begin(), '1');
            } else {
                integer_str.insert(integer_str.begin(), '0');
            }
            integer_part=integer_part>>1;
        }
        
        while(0.0<fractional_part) {
            if(fractional_str.length()>32) return "ERROR";
            
            double new_fractional=2*fractional_part;
            if(new_fractional>=1) {
                fractional_str.push_back('1');
                fractional_part=new_fractional-1.0;
            } else {
                fractional_str.push_back('0');
                fractional_part=new_fractional;
            }
        }
        
        return fractional_str.length()>0? integer_str+"."+fractional_str : integer_str;
        
        
        
    }
};

