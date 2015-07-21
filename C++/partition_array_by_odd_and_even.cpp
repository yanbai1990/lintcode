class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int left=0, right=nums.size();
        for( ;left<right; ) {
            if(nums[left]%2==0) {
                swap(nums[left], nums[--right]);
            } else {
                ++left;
            }
        }
    }
};
