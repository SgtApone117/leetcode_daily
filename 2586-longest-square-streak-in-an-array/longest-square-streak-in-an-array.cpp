class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int maxStreak = 0;

        for(int &num : nums)
        {
            int currStreak = 0;
            long long sqr = num;
            while(st.find(sqr) != st.end())
            {
                currStreak++;
                if(sqr*sqr > 1e5)
                    break;
                sqr*= sqr;             
            }     
            maxStreak = max(maxStreak, currStreak);
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
};