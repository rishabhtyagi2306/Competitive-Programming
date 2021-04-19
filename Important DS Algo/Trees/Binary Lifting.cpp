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
void binary_lifting(ll src, ll par)
{
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
}
ll querry(ll node, ll jump)
{
	if(node == -1 || jump == 0)
		return node;

	for(ll i = 19; i >= 0; i--)
	{
		if(jump >= (1<<i))
		{
			return querry(dp[node][i], jump - (1<<i));
		}
	}
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