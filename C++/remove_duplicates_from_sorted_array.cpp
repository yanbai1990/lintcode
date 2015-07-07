class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size()==0) return 0;
        int index=0;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i]!=nums[index]) {
                nums[++index]=nums[i];
            }
        }
        return index+1;
    }
};


