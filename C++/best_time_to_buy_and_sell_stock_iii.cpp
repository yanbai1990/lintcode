class Solution1 {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty()) return 0;
        
        const int n=prices.size();
        vector<int> left_to_right(n, 0);
        vector<int> right_to_left(n, 0);
        int max_profit_lr=0, min_price_lr=prices[0];
        int max_profit_rl=0, max_price_rl=prices[n-1];
        int max_profit=0;
        
        for(int i=1; i<n; ++i) {
            max_profit_lr=max(max_profit_lr, prices[i]-min_price_lr);
            min_price_lr=min(min_price_lr, prices[i]);
            left_to_right[i]=max_profit_lr;
        }
        for(int i=n-1; i>=0; --i) {
            max_profit_rl=max(max_profit_rl, max_price_rl-prices[i]);
            max_price_rl=max(max_price_rl, prices[i]);
            right_to_left[i]=max_profit_rl;
        }
        
        for(int i=0; i<n; ++i) {
            max_profit=max(max_profit, left_to_right[i]+right_to_left[i]);
        }
        return max_profit;
    }
};

class Solution2 {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = INT_MIN, release2 = INT_MIN;
        
        for (const auto& p : prices) {
            hold1 = max(hold1, -p);
            release1 = max(release1, hold1 + p);
            hold2 = max(hold2, release1 - p);
            release2 = max(release2, hold2 + p);
        }
        
        return release2;
    }
};