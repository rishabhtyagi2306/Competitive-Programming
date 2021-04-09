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

pii bfs(vii adj[], bool vis[], int src)
{
	queue<pii> q;
	q.push({src, 0});
	pii p;
	vis[src] = true;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		for(auto v : adj[p.F])
		{
			if(!vis[v])
			{
				vis[v] = true;
				q.push({v, p.S + 1});
			}
		}
	}
	return p;
}
int main() {
    FASTIO
    int T = 1;
    // cin>>T;
    while(T--)
    {
    	int n, i, j;
    	cin>>n;
    	vii adj[n+1];
    	for(i = 0; i < n-1; i++)
    	{
    		int u, v;
    		cin>>u>>v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	bool vis[n+1] = {false};
    	pii tmp = bfs(adj, vis, 1);
    	for(i = 0; i <= n; i++)
    	{
    		vis[i] = false;
    	}
    	pii ans = bfs(adj, vis, tmp.F);
    	cout<<ans.S<<endl;
    }
    return 0;
}