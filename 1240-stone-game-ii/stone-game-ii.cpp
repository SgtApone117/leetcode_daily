class Solution {
public:
    int n;
    int t[2][101][101];
    int solveForAlice(int person, int index, int M, vector<int>& piles)
    {
        if(index >= n)
            return 0;

        if(-1 != t[person][index][M])
            return t[person][index][M];
        int stones = 0;
        int result = (person == 1) ? INT_MIN : INT_MAX;

        for(int x = 1; x <= min(2*M, n-index); x++)
        {
            stones += piles[index+x-1];
            if(1 == person)
            {
                result = max(result, stones + solveForAlice(0, index+x, max(M, x), piles));
            }
            else
            {
                result = min(result, solveForAlice(1, index+x, max(M, x), piles));
            }
        }
        return t[person][index][M] = result;
    }
    int stoneGameII(vector<int>& piles) 
    {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solveForAlice(1, 0, 1, piles);
    }
};