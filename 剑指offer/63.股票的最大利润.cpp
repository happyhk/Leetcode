class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 0) return 0 ;
        vector<int> dp(len, 0);
        int minNum = prices[0];
        for(int i = 0;i < len; ++i){
            if(i > 0) {
                dp[i] = max(dp[i-1], prices[i] - minNum);
                minNum = min(minNum, prices[i]);
            }
        }
        return dp[len-1];

    }
};
