class Solution {
public:
    int t[101][101];
    int findIndex(int left, int right, string s)
    {
        int i = left+1;
        while(i <= right && s[i] == s[left])
        {
            i++;
        }
        return i;
    }
    int solve(int left, int right, string s)
    {
        if(left == right)
            return 1;
        if(left > right)
            return 0;
        if(-1 != t[left][right])
            return t[left][right];
        int index = findIndex(left, right, s);

        if(index == right+1)
            return 1;

        int basic = 1 + solve(index, right, s);

        int greedy = INT_MAX;
        for(int j = index; j <= right; j++)
        {
            if(s[left] == s[j])
            {
                int ans = solve(index, j-1, s) + solve(j, right, s);
                greedy = min(greedy, ans);
            }
        }
        return t[left][right] = min(greedy, basic);
    }
    int strangePrinter(string s) 
    {
        memset(t, -1, sizeof(t));
        return solve(0, s.length()-1, s); //(left, right)
    }
};