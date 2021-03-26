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
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
 
using namespace std;
using namespace __gnu_pbds;
 
/*------------------------------------------Code Starts From Here------------------------------------------*/

ll seg_tree[400001];
void build_tree(ll a[], ll sii, ll ss, ll se)
{
	if(ss == se)
	{
		seg_tree[sii] = a[ss];
		return ;
	}

	ll mid = (ss + se)/2;
	
	build_tree(a, 2*sii, ss, mid);
	build_tree(a, 2*sii+1, mid+1, se);

	seg_tree[sii] = min(seg_tree[2*sii], seg_tree[2*sii+1]);
}
ll querry(ll sii, ll ss, ll se, ll l, ll r)
{
	if(r < ss || l > se)
		return LLONG_MAX;

	if(l <= ss && r >= se)
		return seg_tree[sii];

	ll mid = (ss + se)/2;
	ll i = querry(2*sii, ss, mid, l, r);
	ll j = querry(2*sii+1, mid+1, se, l, r);

	return min(i, j);
}
int main() {
	FASTIO
	int T = 1;
	// cin>>T;
	while(T--)
	{
		ll n, i, j;
		cin>>n;
		ll a[n+1];
		for(i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		ll q;
		build_tree(a, 1ll, 1ll, n);
		cin>>q;
		while(q--)
		{
			ll l, r;
			cin>>l>>r;
			ll ans = querry(1ll, 1ll, n, l + 1, r + 1);
			cout<<ans<<endl;
		}
	}
	return 0;
}