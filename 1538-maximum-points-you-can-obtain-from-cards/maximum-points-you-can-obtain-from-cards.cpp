class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;

        int sum = 0;
        for(int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }
        sum = lsum;

        int n = cardPoints.size();
        int l = 0;
        int r = n-1;
        while(k > 0)
        {
            lsum -= cardPoints[k-1];
            rsum += cardPoints[r];
            sum = max(sum, lsum+rsum);
            k--;
            r--;
        }
        return sum;
    }
};