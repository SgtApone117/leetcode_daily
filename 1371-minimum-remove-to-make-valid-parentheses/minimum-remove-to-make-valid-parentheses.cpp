class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        unordered_set<int> toRemove;
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') //store index of '('
                st.push(i);
            else  if(s[i] == ')') {
                if(st.empty()) { //invalid ')'
                    toRemove.insert(i);
                } else {
                    st.pop(); //balancing with open '('
                }
            }
        }
        
        //suppose the input is  "(("
        //Then, we won't be adding them in the toRemove set to remove later
        //So, adding here
        while(!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        string result = "";
        
        for(int i = 0; i<n; i++) {
            if(toRemove.find(i) == toRemove.end())
                result.push_back(s[i]);
        }
        
        return result;
    }
};