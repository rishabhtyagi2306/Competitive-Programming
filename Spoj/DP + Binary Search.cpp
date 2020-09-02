//https://www.spoj.com/problems/ACTIV/



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
    ll n;
    while(cin>>n)
    {
        if(n == -1)
            break;
        ll x, y;
        ll i;
        ll dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        pll v[n+1];
        v[0].F = v[0].S = -1;
        for(i = 1; i <= n; i++)
        {
            cin>>v[i].S>>v[i].F;
        }
        sort(v, v+n+1);
        ll modulo = 100000000;
        for(i = 1; i <= n; i++)
        {
            pll aux;
            aux.first = v[i].second;
            aux.second = v[i].second;

            ll ind1 = upper_bound(v,v+n+1,aux) - v -1;
            ll tmp1 = dp[ind1];
            ll tmp2 = dp[i-1];

            dp[i] = (tmp1 + tmp2)%100000000;
        }
        ll ans = dp[n]-1 + 100000000;
        int arr[8];
        i = 7;
        while(i>=0)
        {
            arr[i]=ans%10;
            ans/=10;
            i--;
        }
        for(i = 0; i < 8; i++)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}
