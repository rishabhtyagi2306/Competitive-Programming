#include <bits/stdc++.h>
//#include <boost/math/common_factor.hpp> 
#define ll long long 
#define pb push_back
#define pob pop_back
#define mp make_pair
#define __builtin_popcount CS
#define lcm boost::math::lcm
using namespace std;

bool isPerfectSquare(long double x) 
{   
    long double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
} 
bool isPrime(ll n) 
{ 
    if (n <= 1) 
        return false; 
    for (ll i = 2; i <= floor(sqrt(n)); i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
ll factorial(int n)
{
    ll x = 1e9+7;
    ll fact = 1, i;
    for(i = 1; i <= n ; i++)
        fact = (fact*i)%x;
    return fact;
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}  


void solve(int n, bool prime[])
{
    int cnt = 1, i, b, temp;
    vector<vector<int>> v;
    vector<int> w, ans = {1, 2};
    v.pb(ans);
    for(i = 3; i <= n; i += 2)
    {
        // if(i%2 == 0)
        //     continue;
        if(i != n)
        {
            w.pb(i+1);
            v.pb(w);
            w.clear();
        }
        if(prime[i])
        {
            v[0].pb(i);
            continue;
        }
        else
        {
            //cout<<i<<" ";
            while(1)
            {
                b = v[cnt][0];
                if(gcd(b, i) == 1)
                {
                    v[cnt].pb(i);
                    cnt++;
                    break;
                }
                else
                    cnt++;
            }
        }
    }
    if(n != 1)
    {
        cout<<n/2<<"\n";
    }
    else
    {
        v[0].pob();
        cout<<1<<"\n";
    }
    for(auto k : v)
    {
        cout<<k.size()<<" ";
        temp = 1;
        for(auto j : k)
        {
            if(!(temp != k.size()))
            {
                cout<<j;
            }
            else
            {
                cout<<j<<" ";
                temp++;
            }
        }
        cout<<"\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, p, i;
    cin>>t;
    bool prime[1000001]; 
    memset(prime, true, sizeof(prime)); 
    for (p = 2; p*p <= 1000000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (i = p*p; i <= 1000000; i += p) 
                prime[i] = false; 
        } 
    } 
    // for(i = 1; i <= 1000000; i++)
    //     if(prime[i])
    //         cout<<i<<"\n";
    while(t--)
    {
        int n;
        cin>>n;
        solve(n, prime);
    }
	return 0;
}

