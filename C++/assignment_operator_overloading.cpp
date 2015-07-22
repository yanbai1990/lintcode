class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }
    
    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(this!=&object) {
            char *new_pData=nullptr;
            if(object.m_pData!=nullptr) {
                size_t len=strlen(object.m_pData);
                new_pData=new char[len];
                copy(object.m_pData, object.m_pData+len, new_pData);
            }
            
            if(m_pData!=nullptr) delete [] m_pData;
            
            m_pData=new_pData;
        }
        return *this;
    }
};
