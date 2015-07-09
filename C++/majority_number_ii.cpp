class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        const int k=3;
        unordered_map<int, int> counter;
        for(const auto i:nums) {
            if(counter.find(i)!=counter.end()) {
                counter[i]+=1;
            } else {
                counter[i]=1;
            }
            
            if(counter.size()==k) {
                auto ptr=counter.begin();
                while(ptr!=counter.end()) {
                    (*ptr).second-=1;
                    if((*ptr).second==0) {
                        counter.erase(ptr++);
                    } else {
                        ++ptr;
                    }
                }
            }
        }
        for(auto& i:counter) {
            i.second=0;
        }
        
        pair<int, int> res;
        for(const auto i:nums) {
            if(counter.find(i)!=counter.end()) {
                counter[i]+=1;
            }
            if(counter[i]>res.second) {
                res.first=i;
                res.second=counter[i];
            }
        }
        
        return res.first;
        
        
    }
};

