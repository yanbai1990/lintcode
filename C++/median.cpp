class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        size_t n=nums.size();
        quickSort(nums, 0, n-1);
        if(n%2==0) return nums[n/2-1];
        else return nums[n/2];
    }
    
    void quickSort(vector<int> &nums, int start, int end) {
        if(start<end) {
            int pivot=partition(nums, start, end);
            quickSort(nums, start, pivot-1);
            quickSort(nums, pivot+1, end);
        }
    }
    
    int partition(vector<int> &nums, int start, int end) {
        int x=end;
        int i=start-1, j;
        
        for(j=start; j<end; ++j) {
            if(nums[j]<=nums[x]) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i+1], nums[x]);
        return i+1;
    }
};

