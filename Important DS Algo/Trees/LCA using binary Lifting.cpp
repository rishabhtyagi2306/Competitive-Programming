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

vll adj[2000001];
ll dp[200001][20];
ll lvl[200001];
void dfs(ll src, ll par, ll level = 0)
{
	lvl[src] = level;
	for(auto child : adj[src])
	{
		if(child != par)
		{
			dfs(child, src, level + 1);
		}
	}
}
void binary_lifting(ll src, ll par)
{
	// lvl[src] = ++cnt;
	dp[src][0] = par;
	for(ll i = 1; i < 20; i++)
	{
		if(dp[src][i-1] != -1)
		{
			dp[src][i] = dp[dp[src][i-1]][i-1];
		}
		else
		{
			dp[src][i] = -1;
		}
	}
	for(auto child : adj[src])
	{
		if(child != par)
			binary_lifting(child, src);
	}
	// lvl[src] = ++cnt;
}
ll lift_node(ll node, ll jump)
{
	for(ll i = 19; i >= 0; i--)
	{
		if(jump == 0 || node == -1)
			break;
		if(jump >= (1 << i))
		{
			jump -= (1 << i);
			node = dp[node][i];
		}
	}
	return node;
}
ll querry(ll u, ll v)
{
	if(lvl[u] < lvl[v])
	{
		swap(u, v);
	}
	u = lift_node(u, abs(lvl[u] - lvl[v]));
	if(u == v)
		return u;

	for(ll i = 19; i >= 0; i--)
	{
		if(dp[u][i] != dp[v][i])
		{
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return lift_node(u, 1ll);
}
int main() {
    FASTIO
    int T = 1;
    // cin>>T;
    while(T--)
    {
    	ll n, q, i, j;
    	cin>>n>>q;
    	for(i = 2; i <= n; i++)
    	{
    		ll a;
    		cin>>a;
    		adj[a].pb(i);
    		adj[i].pb(a);
    	}
    	// cnt = 0;
    	dfs(1ll, -1ll);
    	binary_lifting(1ll, -1ll);
    	while(q--)
    	{
    		ll x, y;
    		cin>>x>>y;
    		ll ans = querry(x, y);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}