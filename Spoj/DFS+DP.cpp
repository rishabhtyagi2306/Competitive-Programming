//https://www.spoj.com/problems/PT07X/


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

vii adj[1000002];
int dp[1000002][2];
int visited[1000002][2];
int dfs(int u, int taken, int parent)
{
    if(visited[u][taken] == 1)
        return dp[u][taken];
    visited[u][taken] = 1;
    int ans = 0;
    for(auto v : adj[u])
    {
        if(v != parent)
        {
            if(taken == 1)
                ans += min(dfs(v, 0, u), dfs(v, 1, u)); 
            else
                ans += dfs(v, 1, u);
        }
    }
    return dp[u][taken] = ans+taken;
}
int main() {
    FASTIO
    int n, u, v, i;
    cin>>n;
    
    for(i = 0; i < n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    
    int ans = min(dfs(1, 0, -1), dfs(1, 1, -1));
    cout<<ans<<endl;
    return 0; 
}
