class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start=0;
        int end=num.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(num[mid]>num[end]) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(num[start]<=num[end]) return num[start];
        else return num[end];
    }
};