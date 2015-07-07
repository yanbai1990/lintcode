class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int start=0;
        int end=array.size()-1;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(array[mid]==target) {
                end=mid;
            } else if(array[mid]<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if(array[start]==target) return start;
        else if(array[end]==target) return end;
        return -1;
    }
};
