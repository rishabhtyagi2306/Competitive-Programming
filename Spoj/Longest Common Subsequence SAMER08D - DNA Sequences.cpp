//https://www.spoj.com/problems/SAMER08D/



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
    int n;
    while(cin>>n)
    {
        if(n == 0)
            break;
        string a, b;
        cin>>a>>b;
        int x = a.size(), y = b.size(), i, j, k;
        int dp[10002][10002], cnt[10002][10002];
        for(i = 0; i <= 10001; i++)
            dp[i][0] = 0;
        for(j = 0; j <= 10001; j++)
            dp[0][j] = 0;
        cnt[0][0] = 0;
        for(i = 1; i <= x; i++)
        {
            for(j = 1; j <= y; j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1] == b[j-1])
                    cnt[i][j] = 1 + cnt[i-1][j-1];
                else
                {
                    cnt[i][j] = 0;
                }
                if(cnt[i][j] >= n)
                {
                    for(k = n; k <= cnt[i][j]; k++)
                    {
                        //if((i-k) >= 0 && (j-k) >= 0)
                            dp[i][j] = max(dp[i-k][j-k]+k, dp[i][j]);
                    }
                }
            }
        }
        cout<<dp[x][y]<<endl;
    }
    return 0; 
}
