#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll              long long
#define vii             vector<int>
#define vll             vector<ll>
#define mii             map<int, int>
#define mll             map<ll, ll>
#define sii             set<int>
#define sll             set<ll>
#define umi             unordered_map<int, int>
#define uml             unordered_map<ll, ll>
#define usi             unordered_set<int>
#define usl             unordered_set<ll>
#define pii             pair<int, int>
#define pll             pair<ll, ll> 
#define pb              push_back
#define pf              push_front
#define mk              make_pair
#define endl            "\n"
#define desc            greater<int>()
#define F               first
#define S               second
#define mod             1000000007
#define pi              3.141592653589793238
#define lcm(a,b)        (a/(__gcd(a,b)))*b
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
 
using namespace std;
using namespace __gnu_pbds;
 
/*------------------------------------------Code Starts From Here------------------------------------------*/

int main() {
    FASTIO
    int T = 1;
    // cin>>T;
    while(T--)
    {
        ll n, m, q, i, j, k;
        cin>>n>>m>>q;
        ll g[n+1][n+1];
        ll inf = (ll)1e15;
        memset(g, -1, sizeof(g));
        for(i = 0; i < m; i++)
        {
            ll a, b, c;
            cin>>a>>b>>c;
            if(g[a][b] != -1)
                g[a][b] = g[b][a] = min(g[a][b], c);
            else
            {
                g[a][b] = c;
                g[b][a] = c;
            }
            
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(i == j)
                    g[i][j] = 0;
                if(g[i][j] == -1)
                    g[i][j] = inf;
            }
        }
        for(k = 1; k <= n; k++)
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(g[i][j] == inf)
                    g[i][j] = -1;
                // cout<<g[i][j]<<" ";
            }
            // cout<<endl;
        }
        while(q--)
        {
            ll x, y;
            cin>>x>>y;
            ll ans = g[x][y];
            cout<<ans<<endl;
        }
    }
    return 0;
}