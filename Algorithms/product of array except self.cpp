//Given an array arr of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of arr except arr[i].
//GFG LINK - https://www.geeksforgeeks.org/a-product-array-puzzle/


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
    ll n, i;
    cin>>n;
    ll a[n];
    for(i = 0; i < n; i++)
        cin>>a[i];
    ll p[n], s[n], ans[n];
    p[0] = s[n-1] = 1;
    for(i = 1; i < n; i++)
        p[i] = a[i-1]*p[i-1];
    for(i = n-2; i >=0 ; i--)
        s[i] = s[i+1]*a[i+1];
    for(i = 0; i < n; i++)
        ans[i] = p[i]*s[i];
    for(i = 0; i < n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0; 
}
