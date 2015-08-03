class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        const int n=nums.size();
        
        quickSort(nums, 0, n-1);
        
        return nums[n-k];
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
        int i=start-1, j=start;
        for( ; j<end; j++) {
            if(nums[j]<=nums[x]) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i+1], nums[x]);
        return i+1;
    }
};
