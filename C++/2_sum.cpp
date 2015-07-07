class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> map;
        for(size_t i=0; i<nums.size(); ++i) {
            if(map.find(target-nums[i])!=map.end()) {
                return {map[target-nums[i]], i+1};
            }
            map[nums[i]]=i+1;
        }
        return {};
    }
};