class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        n--;
        int index = 0; 

        while (n > 0) {
            if (index % 4 == 0) {
                st.top() *= n; 
            } else if (index % 4 == 1) {
                st.top() /= n; 
            } else if (index % 4 == 2) {
                st.push(n); 
            } else {
                st.push(-n); 
            }
            index++;
            n--;
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};