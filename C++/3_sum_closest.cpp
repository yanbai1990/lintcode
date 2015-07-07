class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        const int n=nums.size();
        int diff=INT_MAX;
        int ans=0;
        sort(nums.begin(), nums.end());
        for(int a=0; a<n; ++a) {
            if(a>0 && nums[a]==nums[a-1]) continue;
            for(int b=a+1, c=n-1; b<c; ) {
                int sum=nums[a]+nums[b]+nums[c];
                if(sum>target) {
                    --c;
                } else if(sum<target) {
                    ++b;
                } else {
                    return target;
                }
                
                if(abs(target-sum)<diff) {
                    diff=abs(target-sum);
                    ans=sum;
                }
            }
        }
        return ans;
        
    }
};