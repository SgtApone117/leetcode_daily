class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& ch : tokens)
        {
            if(ch == "+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2+val1);
            }
            else if(ch == "-")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2-val1);
            }
            else if(ch == "*")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2*val1);
            }
            else if(ch == "/")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2/val1);
            }
            else
                st.push(stoi(ch));
        }
        return st.top();
    }
};