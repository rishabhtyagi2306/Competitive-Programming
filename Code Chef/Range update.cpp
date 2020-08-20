//https://www.codechef.com/problems/CENS20A



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





int main() {
    FASTIO
    ll n,m;
	cin>>n>>m;
	ll a[n][m],i,j,pre[n][m];
	string s[n];
	for(i=0;i<n;i++)
		cin>>s[i];

	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			a[i][j] = s[i][j]-'0';
			pre[i][j]=0;
		}
	}

	ll q;
	cin>>q;
	ll x1,y1,x2,y2;
	while(q--) {
		cin>>x1>>y1>>x2>>y2;
		x1--;
		y1--;
		y2--;
		x2--;
		pre[x1][y1]++;
		if(x2+1<n && y2+1<m)
			pre[x2+1][y2+1]++;
		if(x2+1<n)
			pre[x2+1][y1]--;
		if(y2+1<m)
			pre[x1][y2+1]--;
	}

	for(i=0;i<m;i++) {
		for(j=1;j<n;j++) {
			pre[j][i] += pre[j-1][i];
		}
	}
	
	for(i=0;i<n;i++) {
		for(j=1;j<m;j++) {
			pre[i][j] += pre[i][j-1];
		}
	}
	
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(pre[i][j]%2) {
				if(a[i][j] == 1)
					cout<<0;
				else
					cout<<1;
			}
			else
				cout<<a[i][j];
		}
		cout<<"\n";
	}

    return 0; 
}
