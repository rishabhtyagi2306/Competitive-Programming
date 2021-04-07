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

const int N = 1e5 + 5;
vector<int> adj[N], vis(N), in(N), low(N);
int timer;
unordered_set<int> s;

void dfs(int node, int par = -1) {
	vis[node] = 1;
	low[node] = in[node] = timer++;
	int c = 0;
	for(auto child : adj[node]) {
		if(child == par) continue;
		
		if(vis[child]) {
			low[node] = min(low[node], in[child]);
		}
		else {
			dfs(child, node);
			low[node] = min(low[node], low[child]);
			if(low[child] >= in[node] and par != -1)
				s.insert(node);
			c++;
		}
	}
}
	
int main() {
	FASTIO
	while(1)
	{
		int n, m, u, v;
		cin >> n >> m;
		
		if(n == 0 and m == 0) break;
		
		for(int i = 1; i <= n; i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		
		for(int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		timer = 0;
		s.clear();
		
		for(int i = 1; i <= n; i++)
			if(!vis[i])
				dfs(i);
		
		cout << s.size() << "\n";
	}
	return 0;
}