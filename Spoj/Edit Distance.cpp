https://www.geeksforgeeks.org/edit-distance-dp-5/
https://www.spoj.com/problems/EDIST/



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



int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
}
int editDistDP(string str1, string str2, int m, int n) 
{  
    int dp[m + 1][n + 1]; 

    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) 
                dp[i][j] = j; 
            else if (j == 0) 
                dp[i][j] = i;  
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];  
            else
                dp[i][j] = 1 + min(dp[i][j - 1], 
                                   dp[i - 1][j], 
                                   dp[i - 1][j - 1]); 
        } 
    } 
  
    return dp[m][n]; 
}
int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;
        int n = a.size(), m = b.size(), i, j;
        int ans = editDistDP(a, b, n, m);
        cout<<ans<<endl;
        // int dp[n+1][m+1];
        // for(i = 0; i <= n; i++)
        //     dp[i][0] = 0;
        // for(j = 0; j <= m; j++)
        //     dp[0][j] = 0;
        // for(i = 1; i <= n; i++)
        // {
        //     for(j = 1; j <= m; j++)
        //     {
        //         if(a[i-1] == b[j-1])
        //             dp[i][j] = dp[i-1][j-1];
        //         else
        //             dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        //     }
        // }
        // cout<<dp[n][m]<<endl;
    }
    return 0; 
}
