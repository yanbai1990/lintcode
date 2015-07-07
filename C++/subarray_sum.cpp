class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int, int> map;
        map[0]=-1;
        int sum=0;
        for(int i=0; i<nums.size(); ++i) {
            sum+=nums[i];
            if(!map.emplace(sum, i).second) {
                return {map[sum]+1, i};
            }
        }
        return {};
        
    }
};
