class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;

        for(auto& price : prices)
        {
            if(price < minPrice)
            {
                secMinPrice = minPrice;
                minPrice = price;
            }
            else
            {
                secMinPrice = min(price, secMinPrice);
            }
        }
        if(secMinPrice + minPrice > money)
        {
            return money;
        }
        return money - (minPrice+secMinPrice);
    }
};