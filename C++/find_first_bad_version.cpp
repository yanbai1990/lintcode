/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
 */
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start=1;
        int end=n;
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if(VersionControl::isBadVersion(mid)) {
                end=mid;
            } else {
                start=mid+1;
            }
        }
        if(VersionControl::isBadVersion(start)) return start;
        else return end;
    }
};

