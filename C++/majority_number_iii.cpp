class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> counter;
        for(const auto i:nums) {
            ++counter[i];
            if(counter.size()==k) {
                auto iter=counter.begin();
                while(iter!=counter.end()) {
                    if(iter->second==1) {
                        counter.erase(iter++);
                    } else {
                        ++iter;
                    }
                }
            }
        }
        for(auto pair:counter) {
            pair.second=0;
        }
        pair<int, int> ans;
        for(const auto i:nums) {
            if(counter.find(i)!=counter.end()) {
                ++counter[i];
                if(counter[i]>ans.second) {
                    ans.first=i;
                    ans.second=counter[i];
                }
            }
        }
        return ans.first;
    }
};

