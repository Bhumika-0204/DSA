class Solution {
public:
    int trap(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    int water = 0;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()) break;

            int distance = i - st.top() - 1;
            int bounded_height = min(arr[i], arr[st.top()]) - arr[top];
            water += distance * bounded_height;
        }
        st.push(i);
    }
    return water;
}
};