//https://www.spoj.com/problems/PIGBANK/
//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/



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
    int t;
    cin>>t;
    while(t--)
    {
    	int e, f, n, i, j;
    	cin>>e>>f;
    	e = f-e;
    	cin>>n;
    	int v[n], w[n];
    	for(i = 0; i < n; i++)
    		cin>>v[i]>>w[i];
    	int dp[e+1];
    	for(i = 1; i <= e; i++)
    		dp[i] = 9999999;
    	dp[0] = 0;
    	for(i = 1; i <= e; i++)
    	{
    		for(j = 0; j < n; j++)
    		{
    			if(w[j] <= i)
    				dp[i] = min(dp[i], dp[i - w[j]] + v[j]);
    		}
    	}
    	if(dp[e] == 9999999)
    		cout<<"This is impossible."<<endl;
    	else
    		cout<<"The minimum amount of money in the piggy-bank is "<<dp[e]<<"."<<endl;
    }
    return 0; 
}
