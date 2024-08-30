class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int maxProfit = 0;
        for(int &price : prices)
        {
            if(minProfit > price)
            {
                minProfit = price;
            }
            else
            {
                maxProfit += price-minProfit;
                minProfit = price;
            }
        }
        return maxProfit;
    }
};