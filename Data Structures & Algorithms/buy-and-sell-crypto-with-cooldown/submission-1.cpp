class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for(int i=1; i<prices.size(); i++){
            int price = prices[i];

            int newHold = max(hold, rest - price);
            int newSold = hold + price;
            int newRest = max(rest, sold);

            hold = newHold;
            sold = newSold;
            rest = newRest;
        }
        return max(rest, sold);
    }   
};
