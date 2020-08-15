//In Coding blocks test Kartik bhaiya gave students an array of n non-negative integers a1, a2, …, an ,
//where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//The task is to find two lines, which together with x-axis forms a container, such that the container contains the most water.
//Note: You may not slant the container.

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
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, 
             tree_order_statistics_node_update> PBDS;




int main() {
    FASTIO
    ll n, i, j, ans = 0;
    cin>>n;
    ll a[n];
    for(i = 0; i < n; i++)
        cin>>a[i];
    i = 0;j = n-1;
    while(i < j)
    {
        ans = max(ans, min(a[i], a[j])*(j-i));
        if(a[i] < a[j])
            i++;
        else
            j--;
    }
    cout<<ans;
    return 0; 
}
