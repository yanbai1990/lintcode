class Solution1 {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        const int n=nums.size();
        int total=n*(n+1)/2;
        for(const int num:nums) {
            total-=num;
        }
        return total;
    }
};

class Solution2 {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int missing=0;
        for(int i=0; i<=nums.size(); ++i) {
            missing^=i;
        }
        
        for(int num:nums) {
            missing^=num;
        }
        return missing;
    }
};
