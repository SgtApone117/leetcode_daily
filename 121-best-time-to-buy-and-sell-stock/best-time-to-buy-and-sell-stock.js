/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxProfit = 0, min = prices[0];
    for(let i = 1; i < prices.length; i++) {
        maxProfit = Math.max(maxProfit, prices[i]-min);     
        min = Math.min(min, prices[i]);  
    }
    return maxProfit;
};