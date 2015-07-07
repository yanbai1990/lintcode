class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int pos=0;
        int gas_remain=0;
        int gas_total=0;
        for(int i=0; i<gas.size(); ++i) {
            gas_total+=gas[i]-cost[i];
            gas_remain+=gas[i]-cost[i];
            if(gas_remain<0) {
                gas_remain=0;
                pos=i+1;
            }
        }
        return gas_total>=0?pos:-1;
    }
};
