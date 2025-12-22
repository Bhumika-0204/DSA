class NestedIterator {
    stack<vector<NestedInteger>::iterator> st;
    stack<vector<NestedInteger>::iterator> endSt;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push(nestedList.begin());
        endSt.push(nestedList.end());
    }

    int next() {
        hasNext();  // ensure top is integer
        int val = st.top()->getInteger();
        st.top()++;
        return val;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top() == endSt.top()) {
                st.pop();
                endSt.pop();
                continue;
            }

            if (st.top()->isInteger()) {
                return true;
            }

            // It's a list
            auto &lst = st.top()->getList();
            st.top()++;  // move current iterator
            st.push(lst.begin());
            endSt.push(lst.end());
        }
        return false;
    }
};
