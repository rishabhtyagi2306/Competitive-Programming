//https://www.spoj.com/problems/TRIP/

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
 
 
 
int dp[85][85];
string a, b;
map<string,bool> processed[85][85];
void findseq(int i, int j,set<string>& sequences,string word)
    {
        if(processed[i][j].find(word)!=processed[i][j].end())
            return;
    if(i==0||j==0)
    {
        sequences.insert(word);
    }
    else if(a[i-1]==b[j-1])
    {
        word = a[i-1] + word;
        findseq(i-1,j-1,sequences,word);
    }
    else if(dp[i][j-1]>dp[i-1][j])
    {
        findseq(i,j-1,sequences,word);
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        findseq(i-1,j,sequences,word);
    }
    else
    {
        findseq(i,j-1,sequences,word);
        findseq(i-1,j,sequences,word);
    }
    processed[i][j][word] = true;
}
int main() {
    FASTIO
    int t;
    cin>>t;
    set<string> sequences;
    while(t--)
    {
        cin>>a>>b;
        int n = a.size(), m = b.size(), i, j;
        for(i = 0; i < 85; i++)
            for(j = 0; j < 85; j++)
                dp[i][j] = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        sequences.clear();
        findseq(a.size(),b.size(),sequences,"");
 
        for(set<string>::iterator k=sequences.begin();k!=sequences.end();++k)
        {
            cout<<*k<<endl;
        }
        cout<<endl;
    }
    return 0; 
} 
