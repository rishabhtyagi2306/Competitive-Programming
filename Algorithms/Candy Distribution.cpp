//Given N students in a line and their marks, you have to distribute candies in such a way that every child must get atleast one candy and children with strictly higher marks than their neighbours get more candies than them.
//You have to tell what is the minimum number of candies needed for this task.


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
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    int n, i;
    cin>>n;
    int a[n], b[n];
    for(i = 0; i < n; i++)
    	cin>>a[i];
    b[0] = 1;
    for(i = 1; i < n; i++)
    {
    	if(a[i] > a[i-1])
    		b[i] = b[i-1]+1;
    	else
    		b[i] = 1;
    }
    for(i = n-2; i >= 0; i--)
    {
    	if(a[i] > a[i+1])
    	{
    		if(b[i] <= b[i+1])
    			b[i] = b[i+1]+1;
    	}
    }
    int sum = 0;
    for(i = 0; i < n; i++)
    	sum += b[i];
    cout<<sum;
    return 0; 
}
