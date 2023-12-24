class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        int score = INT_MIN;
        int zeroes = 0;
        int ones = 0;
        for(int i = 0; i <= n-2; i++)
        {
            if(s[i] == '1')
            {
                ones++;
            }
            else
            {
                zeroes++;
            }
           score = max(score, zeroes-ones);
        }
        if(s[n-1] == '1')
        {
          ones++;  
        }
       return score + ones;
    }
};