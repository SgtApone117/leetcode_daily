class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> vec(100);
        vec[1] = 1;
        vec[2] = 1;
        vec[3] = 2;
        for(int i = 4; i <= n; i++){
            int sum = i;
            for(int j = 1; j <= sum; j++)
            {
                int x = j;
                int y = sum - x;
                vec[i] = max({vec[i], x*y, vec[x]*y, x * vec[y], vec[x]*vec[y]});
            }
        }
        return vec[n];
    }
};