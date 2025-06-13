/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minVal = prices[0];
    let maxProfit = 0;
    for(let i = 1; i < prices.length; i++) {
        if(prices[i]-minVal > maxProfit) {
            maxProfit = prices[i]-minVal;
        }
        if(prices[i] < minVal) {
            minVal = prices[i];
        }
    }
    return maxProfit;
};