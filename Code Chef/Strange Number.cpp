#include <bits/stdc++.h>
//#include <boost/math/common_factor.hpp> 
#define ll long long 
#define pb push_back
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

unordered_map<ll, int> m;

void factorize(ll n) 
{ 
    int count = 0; 
    while (!(n % 2)) { 
        n >>= 1;  
        m[2]++; 
    } 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            m[i]++; 
            n = n / i; 
        } 
    } 
    if (n > 2) 
        m[n]++; 
} 

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll x, k, cnt = 0, i;
        cin>>x>>k;
        factorize(x);
        for(auto i : m)
            cnt += i.second;
        m.clear();
        if(cnt < k)
            cout<<0<<"\n";
        else
            cout<<1<<"\n";
    }
	return 0;
}
