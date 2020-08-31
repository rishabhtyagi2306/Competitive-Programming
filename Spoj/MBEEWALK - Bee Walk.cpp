//https://www.spoj.com/problems/MBEEWALK/


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
    int dx[]={0,0,1,1,-1,-1};
    int dy[]={1,-1,1,0,0,-1};
    static int dp[15][40][40]={0}; //# steps; x coord; y coord
    int i,j,k,m;
    dp[0][20][20]=1;
    for (i=1; i<=14; i++)
        for (j=1; j<39; j++)
            for (k=1; k<39; k++)
                for (m=0; m<6; m++)
                    dp[i][j][k]+=dp[i-1][j+dx[m]][k+dy[m]];
    scanf("%d",&i);
    while (i--)
    {
        scanf("%d",&j);
        printf("%d\n",dp[j][20][20]);
    }
    return 0; 
}
