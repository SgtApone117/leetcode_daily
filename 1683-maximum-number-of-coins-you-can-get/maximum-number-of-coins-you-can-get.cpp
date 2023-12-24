class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles), end(piles));
        int result = 0;
        int bob = 0;
        int M = n-2;
        while(M > bob)
        {
            result += piles[M];
            M -= 2;
            bob++;
        }
        return result;
    }
};