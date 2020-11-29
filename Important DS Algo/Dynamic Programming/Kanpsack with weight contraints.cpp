// Atcoder Educational Dp Knapsack 2


#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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
#define lcm(a,b)        (a/(__gcd(a,b)))*b
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, 
			 tree_order_statistics_node_update> PBDS;



int main() {
	FASTIO
	int T = 1;
	// cin>>T;
	while(T--)
	{
		ll n, w, i, j;
		cin>>n>>w;
		ll wt, v;
		vll dp(1e5+5, 1e9+10);
		ll sum = 0;
		dp[0] = 0;
		for(i = 0; i < n; i++)
		{
			cin>>wt>>v;
			for(j = 1e5; j >= v; j--)
			{
				dp[j] = min(dp[j], dp[j-v]+wt);
			}
			sum += v;
		}
		ll ans = 0;
		for(i = 0; i <= sum; i++)
		{
			if(dp[i] != LLONG_MAX && dp[i] <= w)
			{
				ans = i;
				// return 0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}