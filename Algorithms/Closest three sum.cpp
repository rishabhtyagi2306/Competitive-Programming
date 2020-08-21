//For the coding blocks placement test , kartik bhaiya decided to give students an array arr of n integers and an integer target. The task is to return the sum of three integers in arr such that their sum is closest to target.
//Assume that each input would have exactly one solution.


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
    int n, k, i, r, l;
    cin>>n>>k;
    int a[n];
    for(i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a+n);
    int ans = INT_MAX, sum = 0, res;
    for(i = 0; i < n-3; i++)
    {
        l = i+1; r = n-1;
        sum = a[i] + a[l] + a[r];
        while(l < r)
        {
            if(ans > abs(k-sum))
            {
                ans = abs(k-sum);
                res = sum;
            }
            if(sum > k)
            {
                sum -= a[r];
                r--;
                sum += a[r];
            }
            else if(sum < l)
            {
                sum -= a[l];
                l++;
                sum += a[l];
            }
            else
                break;
        }
    }
    cout<<res<<endl;
    return 0; 
}
