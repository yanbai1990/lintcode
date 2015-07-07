class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left=0;
        int right=nums.size();
        while(left<right) {
            if(nums[left]<k) {
                ++left;
            } else {
                swap(nums[left], nums[--right]);
            }
        }
        return left;
    }
};