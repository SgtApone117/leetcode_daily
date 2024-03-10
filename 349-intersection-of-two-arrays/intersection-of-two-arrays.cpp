class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        int max_size, min_size;
        set<int> s,s1;
        vector<int> vec;
        if(nums1.size() > nums2.size())
        {
            for(int i = 0; i < nums1.size(); i++)
            {
                if(s.find(nums1[i]) != s.end())
                    continue;
                s.insert(nums1[i]);
            }
            for(int i = 0; i < nums2.size(); i++)
            {
                if(s.find(nums2[i]) == s.end())
                {
                    continue;
                }
                s1.insert(nums2[i]);
            }
            for (auto it = s1.begin(); it != s1.end(); it++) {
                    vec.emplace_back(*it);
            }
        }   
        else
        {
            for(int i = 0; i < nums2.size(); i++)
            {
                if(s.find(nums2[i]) != s.end())
                    continue;
                s.insert(nums2[i]);

            }
            for(int i = 0; i < nums1.size(); i++)
            {
                if(s.find(nums1[i]) == s.end())
                {
                    continue;
                }
                s1.insert(nums1[i]);
            }
            for (auto it = s1.begin(); it != s1.end(); it++) {
                    vec.emplace_back(*it);
            }
        }
        
        return vec;
    }
};