//https://www.spoj.com/problems/PHIDIAS/


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



int dp[1000][1000];
int solve(pii p[], int w, int h, int n)
{
    int res = w*h;
    if(dp[w][h] != -1)
        return dp[w][h];
    for(int i = 0; i < n; i++)
    {
        if(p[i].F <= w && p[i].S <= h)
        {
            res = min(res, solve(p, w-p[i].F, h, n) + solve(p, p[i].F, h-p[i].S, n));
            res = min(res, solve(p, w, h-p[i].S, n) + solve(p, w-p[i].F, p[i].S, n));
        }
    }
    return dp[w][h] = res;
}
int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int w, h, n, i;
        cin>>w>>h>>n;
        pii p[n];
        for(i = 0; i < n; i++)
            cin>>p[i].F>>p[i].S;
        int ans = solve(p, w, h, n);
        cout<<ans<<endl;
    }
    return 0;
}
