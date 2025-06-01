class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int temp;
        int profit=0;
        int mini=prices[0];
        for(int i=0;i<n;i++){
            temp = prices[i]-mini;
            profit=max(temp,profit);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};
