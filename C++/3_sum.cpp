class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    // especially care about duplicated triplets
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(size_t a=0; a<nums.size()-2; ++a) {
            if(a>0 && nums[a]==nums[a-1]) continue;
            for(size_t b=a+1, c=nums.size()-1; b<c; ) {
                if(b-1>a && nums[b]==nums[b-1]) {
                    ++b;
                }else if(c+1<nums.size() && nums[c]==nums[c+1]) {
                    --c;
                } else {
                    int sum=nums[a]+nums[b]+nums[c];
                    if(sum==0) {
                        res.push_back({nums[a], nums[b++], nums[c--]});
                    } else if(sum<0) {
                        ++b;
                    } else {
                        --c;
                    }
                }
            }
        }
        return res;
    }
};

