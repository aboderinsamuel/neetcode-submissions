class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int result = 0;

        for(int price : prices){
            int profit = price - minPrice;
            minPrice = min(minPrice, price);
            result = max(profit, result);
        }
        return result;
    }
};
