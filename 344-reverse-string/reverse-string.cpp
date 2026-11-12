class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);

        }
        vector<char>res;
        while(!st.empty()){
            char c=st.top();
            st.pop();
            res.push_back(c);
        }
        s=res;
    }
};