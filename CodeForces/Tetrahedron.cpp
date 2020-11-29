//https://codeforces.com/problemset/problem/166/E

/*
Obvious solution with dynamics: you need to know only how many moves are left and where is the ant. This is 4n states, each with 3 options – most of such solution passes. Observe that the vertices A, B, C are equivalent. This allows writing such solution:

int zD = 1;
int zABC = 0;
for (int i = 1; i <= n; i++) {
	int nzD = zABC * 3LL % MOD;
	int nzABC = (zABC * 2LL + zD) % MOD;
	zD = nzD;
	zABC = nzABC;
}
cout << zD;
Also this problem could be solved by log(n) with binary exponentiation of some 2×2 matrix into power n.
*/




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
    cin>>n;
    vll dp(n+1);
    dp[0] = 0;
    dp[1] = 0;
    ll i;
    for(i = 2; i <= n; i++)
    {
        if(i%2 == 0)
            dp[i] += (((dp[i-1]*3)+3))%mod;
        else
            dp[i] += ((dp[i-1]*3)-3)%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
