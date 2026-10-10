class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxprofit = 0;
        int profit;
        int mn = prices[0];

        for(int i=1; i<n; i++) {
            mn = min(mn,prices[i-1]);

            profit = prices[i] - mn;

            if(profit > 0) {
                mxprofit = max(mxprofit,profit);
            }
        }
        return mxprofit;
    }
};

//Optimal
//TC = O(n)
//SC = O(1)