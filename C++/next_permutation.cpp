class Solution1 {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int pivot=nums.size()-2;
        while(pivot>=0) {
            if(nums[pivot]<nums[pivot+1]) {
                break;
            }
            --pivot;
        }
        
        if(pivot>=0) {
            int change;
            for(int i=pivot+1; i<nums.size(); ++i) {
                if(nums[i]>nums[pivot]) {
                    change=i;
                }
            }
            swap(nums[pivot], nums[change]);
        }
        
        reverse(nums.begin()+pivot+1, nums.end());
        return nums;
    }
};

class Solution2 {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};
