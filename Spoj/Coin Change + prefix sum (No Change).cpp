//https://www.spoj.com/problems/NOCHANGE/



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
    ll k, n, i, j;
    cin>>k>>n;
    ll a[n];
    for(i = 0; i < n; i++)
        cin>>a[i];
    for(i = 1; i < n; i++)
        a[i] += a[i-1];
    bool dp[k+1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(i = 1; i <= k; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[j] <= i)
                dp[i] = dp[i] || dp[i - a[j]];
        }
    }
    if(dp[k])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0; 
}
