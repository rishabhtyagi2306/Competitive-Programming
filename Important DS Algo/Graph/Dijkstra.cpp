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
		int n, m, i, j;
		cin>>n>>m;
		vector<pii> adj[n+1];
		int inf = INT_MAX;
		for(i = 0; i < m; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].pb(mk(v, w));
			adj[v].pb(mk(u, w));
		}
		int dist[n+1];
		for(i = 0; i <= n; i++)
		{
			dist[i] = inf;
		}
		bool vis[n+1] = {false};
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({0, 1});
		dist[1] = 0;
		int path[n+1];
		memset(path, -1, sizeof(path));
		while(!pq.empty())
		{
			int u = pq.top().S;
			pq.pop();
			vis[u] = true;
			if(u == n)
				break;
			for(auto &j : adj[u])
			{
				int v = j.F;
				int w = j.S;
				if(!vis[v] && dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					path[v] = u;
					pq.push({dist[v], v});
				}
			}
		}
		if(vis[n])
		{
			int start = n;
			vii ans;
			ans.pb(start);
			while(start != -1)
			{
				ans.pb(path[start]);
				start = path[start];
			}
			reverse(ans.begin(), ans.end());
			for(i = 1; i < ans.size(); i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}