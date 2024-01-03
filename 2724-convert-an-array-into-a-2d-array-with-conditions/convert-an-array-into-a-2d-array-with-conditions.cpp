class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        //unordered_map<int, int> mp;
        //Since 1 <= nums[i] <= nums.length (you can also use vector of size n)
        vector<int> mp(n+1);
        
        vector<vector<int>> result;

        for(int &num : nums) {
            int freq = mp[num];
            
            if(freq == result.size()) {
                result.push_back({});
            }
            
            result[freq].push_back(num);
            mp[num]++;
        }
        
        return result;
        
    }
};