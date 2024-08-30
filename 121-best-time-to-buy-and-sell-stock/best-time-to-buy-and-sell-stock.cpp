class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MAX;
        int maxProfit = 0;
        for(int &price : prices)
        {
            if(price < minValue)
            {
                minValue = price;
            }
            else
            {
                maxProfit = max(maxProfit, price-minValue);
            }
        }
        return maxProfit;
    }
};