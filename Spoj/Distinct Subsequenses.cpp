//https://www.spoj.com/problems/DSUBSEQ/
//https://www.geeksforgeeks.org/count-distinct-subsequences/



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



int countSub(string str) 
{ 
    vector<ll> last(256, -1);  
    ll n = str.length();  
    ll dp[n + 1]; 
    dp[0] = 1; 
    for (int i = 1; i <= n; i++) { 
        dp[i] = (2 * dp[i - 1])%mod;
        if (last[str[i - 1]] != -1) 
            dp[i] = (dp[i] - dp[last[str[i - 1]]] + mod)%mod;  
        last[str[i - 1]] = (i - 1); 
    } 
  
    return (dp[n])%mod; 
} 
int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<countSub(s)<<endl;
    }
    return 0; 
}
