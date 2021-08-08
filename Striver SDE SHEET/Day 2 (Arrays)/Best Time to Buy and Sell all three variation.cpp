// Best time to buy and sell 1 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, j;
        int ans = 0;
        int mx = prices[n-1];
        
        for(i = n-2; i >= 0; i--)
        {
            ans = max(ans, mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        
        return ans;
    }
};

// Best time to buy and sell 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, ans = 0, n = prices.size();
        int mn = prices[0], mx = prices[0];
        for(i = 1; i < n; i++)
        {
            if(prices[i-1] > prices[i])
            {
                ans += abs(mx - mn);
                mn = mx = prices[i];
            }
            mx = max(mx, prices[i]);
            mn = min(mn, prices[i]);
        }
        ans += abs(mx - mn);
        return ans;
    }
};

// Best time to buy and sell 3
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, j;
        int dp[3][n];
        memset(dp, 0, sizeof(dp));
        int k = 2; // This approach works for any value of K in O(K*N). 
        for(i = 1; i <= k; i++)
        {
            int mx = INT_MIN;
            for(j = 1; j < n; j++)
            {
                mx = max(mx, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j] + mx);
            }
        }
        
        return dp[k][n-1];
    }
};