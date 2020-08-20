//https://www.spoj.com/problems/RENT/
//Binary Search - https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/


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




struct plane{
	ll s, e, c;
};
bool cmp(plane a, plane b)
{
	return a.e < b.e;
}
ll dp[10001];
ll find_next(plane a[], int i)
{
	for(int j = i-1; j >= 0; j--)
	{
		if(a[j].e <= a[i-1].s)
			return j;
	}
	return -1;
}
ll rec(plane a[], int n)
{
	if(n == 1)
		return dp[n] = a[n-1].c;
	if(dp[n] != -1)
		return dp[n];
	ll inc_prf = a[n-1].c;
	ll inc = find_next(a, n);
	if(inc != -1)
		inc_prf += rec(a, inc+1);
	ll exc_prf = rec(a, n-1);
	return dp[n] = max(inc_prf, exc_prf);
}
int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
    	ll n, i, x;
    	memset(dp, -1, sizeof(dp));
    	cin>>n; 
    	plane a[n];
    	for(i = 0; i < n; i++)
    	{
    		cin>>a[i].s>>x>>a[i].c;
    		a[i].e = a[i].s+x;
    	}
    	sort(a, a+n, cmp);
    	// for(i = 0; i < n; i++)
    	// 	cout<<a[i].s<<" "<<a[i].e<<endl;
    	cout<<rec(a, n)<<endl;
    }
    return 0; 
}
