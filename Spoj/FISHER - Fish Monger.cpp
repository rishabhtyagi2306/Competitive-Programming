//https://www.spoj.com/problems/FISHER/




#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll              long long
#define vii             vector<int>
#define vll             vector<ll>
#define mii             map<int, int>
#define mll             map<ll, ll>
#define si              set<int> 
#define sl              set<ll>
#define umi             unordered_map<int, int>
#define uml             unordered_map<ll, ll>
#define usi             unordered_set<int>
#define usl             unordered_set<ll>
#define maxpq           priority_queue<int>
#define minpq           priority_queue<int,vii,greater<int>()>
#define pii             pair<int, int>
#define pll             pair<ll, ll> 
#define pb              push_back
#define pf              push_front
#define mp              make_pair
#define endl            "\n"
#define desc            greater<int>()
#define F               first
#define S               second
#define mod             1000000007
#define pi              3.141592653589793238
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, 
             tree_order_statistics_node_update> PBDS;




int main() {
    FASTIO
    int n, t;
    while(cin>>n>>t)
    {
        if(n == 0 && t == 0)
            break;
        int a[n][n], b[n][n];
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cin>>a[i][j];
        }
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin>>b[i][j];
        int dp[n+1][t+1];
        for(i = 0; i <= n; i++)
            for(j = 0; j <= t; j++)
                dp[i][j] = 999999;
        for(i = 0; i <= t; i++)
            dp[1][i] = 0;
        for(i = 1; i <= t; i++)
        {
            for(j = 1; j <= n; j++)
            {
                for(k = 1; k <= n; k++)
                {
                    if(j == k)
                        continue;
                    if(a[k-1][j-1] > i)
                        continue;
                    else
                        dp[j][i] = min(dp[j][i], b[k-1][j-1] + dp[k][i - a[k-1][j-1]]);
                }
            }
        }
        if(dp[n][t] == 999999)
            cout<<-1<<endl;
        else
        {
            int ans;
            for(i = 0; i <= t; i++)
            {
                if(dp[n][i] == dp[n][t])
                {
                    ans = i;
                    break;
                }
            }
            cout<<dp[n][t]<<" "<<ans<<endl;
        }
    }
    return 0; 
}
