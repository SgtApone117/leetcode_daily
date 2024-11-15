class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        for(int &num : nums2)
        {
            while(!st.empty() && st.top() < num)
            {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> final(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(mp.find(nums1[i]) != mp.end())
            {
                final[i] = mp[nums1[i]];
            }
        }
        return final;
    }
};