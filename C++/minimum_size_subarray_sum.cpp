class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int start=0;
        int minLen=INT_MAX;
        int sum=0;
        
        for(int i=0; i<nums.size(); ) {
            if(sum+nums[i]<s) {
                sum+=nums[i];
                ++i;
            } else {
                while(sum+nums[i]>=s) {
                    minLen=min(minLen, i-start+1);
                    sum-=nums[start];
                    ++start;
                }
            }
        }
        
        if(minLen==INT_MAX) return -1;
        
        return minLen;
    }
};
