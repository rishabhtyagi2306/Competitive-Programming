//https://www.spoj.com/problems/BORW/


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



ll dp[201][201][201];
int main() {
    FASTIO
    ll n;
    while(cin>>n)
    {
        if(n == -1)
            break;
        ll a[n+1];
        ll i;
        for(i = 1; i <= n; i++)
            cin>>a[i];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int lb = i + 1; lb <= n + 1; lb++)
            {
                for(int lw = i + 1; lw <= n + 1; lw++)
                {
                    dp[i][lb][lw] = dp[i - 1][lb][lw] + 1;

                    if(lb > n || arr[i] < arr[lb])
                    {
                        dp[i][lb][lw] = min(dp[i][lb][lw], dp[i - 1][i][lw]);
                    }

                    if(lw > n || arr[i] > arr[lw])
                    {
                        dp[i][lb][lw] = min(dp[i][lb][lw], dp[i - 1][lb][i]);
                    }
                }
            }
        }
        cout<<dp[n][n+1][n+1]<<endl;
    }
    return 0; 
}
