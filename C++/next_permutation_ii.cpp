class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        auto rfirst=nums.rbegin();
        auto rlast=nums.rend();
        
        auto pivot=next(rfirst);
        
        while(pivot!=rlast && *pivot>=*prev(pivot)) {
            ++pivot;
        }
        
        if(pivot==rlast) {
            reverse(rfirst, rlast);
            return;
        }
        
        auto change=find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        
    }
};
