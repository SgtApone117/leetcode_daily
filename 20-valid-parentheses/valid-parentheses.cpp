class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char& ch : s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if(!st.empty() && (ch == ')' && st.top() == '(') ||
             (ch == '}' && st.top() == '{') || 
             (ch == ']' && st.top() == '['))
                st.pop();
            else
                st.push(ch);
        }
        return st.empty();
    }
};