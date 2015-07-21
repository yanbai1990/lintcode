class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution *instance;
        return instance;
    }
    
    //Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;
    
private:
    Solution() {}
    ~Solution() {}
};