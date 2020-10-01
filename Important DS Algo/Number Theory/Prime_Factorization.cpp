#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define ll                  long long
#define ld                  long double
#define vi                  vector<int>
#define pii                 pair<int,int>
#define vpii                vector< pair<int,int> >
#define uset                unordered_set
#define umap                unordered_map
#define maxpq               priority_queue<int>
#define minpq               priority_queue<int,vi,greater<int>()>

#define all(v)              v.begin(),v.end()
#define part(v,s,e)         v.begin()+s,v.begin()+e
#define rev(v)              reverse(v.begin(),v.end())
#define sz(x)               (int)x.size()
#define def(v)              memset(v,-1,sizeof(v));
#define def0(v)             memset(v,0,sizeof(v));
#define minv(a)             *min_element(all(a))
#define maxv(a)             *max_element(all(a))
#define sumv(a)             accumulate(all(a),0)

#define lb                  lower_bound         // returns pointer to the "first position of num" if number is present in the container. Returns pointer to the "position of next higher number greater than num" if num is not present.   
#define ub                  upper_bound         // returns pointer to the "first position of the next higher number than last occurence of num" if num is present in the container. Returns pointer to the position of next higher number than num if container does not contain occurence of num.
#define desc                greater<int>()
#define pb                  emplace_back
#define mp                  make_pair
#define F                   first
#define S                   second

#define mod                 1000000007
#define inf                 1000000000000000
#define infty               1000000000000000000LL
#define md                  998244353
#define PI                  acos(-1.0)
#define endl                "\n"
#define rr                  return
#define br                  cout<<"\n";
#define hr                  for(int i=0;i<40;i++)    cout<<"-";cout<<endl;

#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a/(__gcd(a,b)))*b

#define setbits(x)          __builtin_popcountll(x)
#define leadzero(x)         __builtin_clzll(x)
#define trailzero(x)        __builtin_ctzll(x)

#define ip(v)               for(auto& i:v)    cin>>i;
#define op(v)               for(auto i:v)    cout<<i<<" ";cout<<endl;
#define deb(x)              cout <<"Value of " #x << " : " << x << endl;

#define ordered_set         tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cout << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif

//------------------------------Prime Factorization------------------------------//

// Time Complexity: O(sqrt(n))


vpii prime_factors; // vector pair to store the primes and its power in the prime factorization of the number

void PrimeFactorization(int n)
{

    int pwr=0;
    while(n%2==0)
    {
        n/=2;
        pwr++;  // power of that prime number
    }
    if(pwr!=0)
        prime_factors.pb(mp(2,pwr));


    for(int i=3;i<=sqrt(n);i+=2)
    {
        pwr=0;
        while(n%i==0)
        {
            n/=i;
            pwr++;
        }
        if(pwr!=0)
            prime_factors.pb(mp(i,pwr));
    }

    if(n>1)
        prime_factors.pb(mp(n,1));

}

void solve()
{    
    
    int n;
    cin>>n;

    PrimeFactorization(n);

    cout<<"Prime Factorization of "<<n<<":\n";
    for(auto i:prime_factors)
        cout<<i.F<<"^"<<i.S<<" * ";
    
    br;
    
}    

int32_t main()
{

    fastio
    cout<<setprecision(15)<<fixed;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif

    int t=1;
    // cin>>t;

    for(int i=1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<" : "<<endl;
        solve();
    }
    
    #ifndef ONLINE_JUDGE    
        cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    #endif

    return 0;
}