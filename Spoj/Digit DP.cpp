//https://www.spoj.com/problems/CPCRC1C/


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



int arr[1001];
ll dp[11][100][2];
 
ll getSum(int pos , int n , ll sum , bool flag)
{
    if(pos > n) return sum;
 
    if(dp[pos][sum][flag] != -1) return dp[pos][sum][flag];
 
    int limit = 9;
    if(!flag) limit = arr[pos];
 
    ll res = 0;
    for(int i=0;i<=limit;i++)
    {
        if(flag || i < limit)
            res += getSum(pos + 1 , n , sum + i , true);
        else
            res += getSum(pos + 1 , n , sum + i , false);
    }
 
    return dp[pos][sum][flag] = res;
}
 
int digitSum(string num)
{
    int res = 0;
    for(char digit : num)
    res += digit - '0';
 
    return res;
}
int main() {
    FASTIO
    string a, b;
    while(cin>>a>>b)
    {
        if(a == "-1" && b == "-1")
            break;
        
        int i;
        for(i = 1; i <= a.size(); i++)
            arr[i] = a[i-1]-'0';
        memset(dp, -1, sizeof(dp));
        ll L = getSum(1, a.size(), 0, false);
        // cout<<L<<" ";
        memset(dp, -1, sizeof(dp));
        for(i = 1; i <= b.size(); i++)
            arr[i] = b[i-1]-'0';
        ll R = getSum(1, b.size(), 0, false);
        // cout<<R<<endl;
        ll ans = R-L + digitSum(a);
        cout<<ans<<endl;
    }
    return 0;
}
