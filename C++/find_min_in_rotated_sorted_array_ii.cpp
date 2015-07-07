class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start=0;
        int end=num.size()-1;
        int ans=INT_MAX;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(ans>num[mid]) {
                ans=num[mid];
            } else if(num[mid]<num[end]) {
                end=mid;
            } else if(num[mid]>num[end]){
                start=mid;
            } else {
                end=end-1;
            }
        }
        if(num[start]<ans) ans=num[start];
        if(num[end]<ans) ans=num[end];
        return ans;
    }
};
