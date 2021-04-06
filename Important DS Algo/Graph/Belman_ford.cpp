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

struct graph{
	int first;
	int second;
	int third;
};
int main() {
	FASTIO
	int T = 1;
	// cin>>T;
	while(T--)
	{
		ll n, m, i, j, k;
		cin>>n>>m;
		ll INF = (ll)1e17;
		ll NINF = (-1) * INF;
		vector<graph> adj;
		adj.resize(m);
		for(i = 0; i < m; i++)
		{
			graph a;
			cin>>a.first>>a.second>>a.third;
			// a.third *= (-1);
			adj[i] = a;
		}
		ll dist[n+1] = {0};
		for(i = 2; i <= n; i++)
		{
			dist[i] = INF;
		}
		for(int i = 1; i < n; ++i)
		{
			for(auto e: adj)
			{
				int u = e.first;
				int v = e.second;
				int d = e.third;
				if(dist[u] == INF) 
					continue;
				dist[v] = min(dist[v], d+dist[u]);
				dist[v] = max(dist[v], NINF);
			}
		} // n relaxations
	 
		for(int i = 1; i < n; ++i)
		{
			for(auto e : adj)
			{
				int u = e.first;
				int v = e.second;
				int d = e.third;
				if(dist[u] == INF) 
					continue;
				dist[v] = max(dist[v], NINF);
				if(dist[u]+d < dist[v])
				{
					dist[v] = NINF;
				}
			}
		}

		if(dist[n] == NINF)
		{
			cout<<-1<<endl;
			break;
		}
		else
		{
			ll ans = (-1) * dist[n];
			cout<<ans<<endl;
		}
	}
	return 0;
}