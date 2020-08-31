//https://www.spoj.com/problems/MIXTURES/
//https://www.youtube.com/watch?v=XHjjIJxnAJY




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



ll a[1000];
ll dp[1000][1000];
ll sum(ll s, ll e)
{
    ll ans = 0;
    for(int i = s; i <= e; i++)
    {
        ans = (ans+a[i])%100;
    }
    return ans;
}
ll solve(ll i, ll j)
{
    if(i >= j)
        return dp[i][j] = 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = LLONG_MAX;
    for(int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j) + sum(i, k)*sum(k+1, j));
    }
    return dp[i][j];
}
int main() {
    FASTIO
    ll n;
    while(cin>>n)
    {
        memset(dp, -1, sizeof(dp));
        int i;
        for(i = 0; i < n; i++)
            cin>>a[i];
        ll ans = solve(0, n-1);
        cout<<ans<<endl;
    }
    return 0; 
}
