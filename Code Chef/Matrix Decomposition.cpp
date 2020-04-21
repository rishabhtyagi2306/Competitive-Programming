/*              ****      Author : Rishabh Tyagi      **** 
                ****          Language : C++          ****     
        ****    First, solve the problem. Then, write the code.    ****
*/


#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define __builtin_popcount setbits
#define endl "\n"
#define desc greater<int>()
#define F first
#define S second
#define mod 1000000007

using namespace std;

ll prime[1000000];
void sieve()
{
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<1000000;i++)
        prime[i]=1;

    for(int i=2;i*i<1000000;i++)
        if(prime[i]==1)
            for(int j=i*i;j<1000000;j+=i)
                prime[j]=0;
}
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
ll lcm(ll a, ll b)
{ 
    return (a / __gcd(a, b)) * b; 
}
ll power(ll n , ll p ){
    if(p==0)
       return 1;
 
     ll res = power((n*n)%mod,p/2);
     if(p%2==1)
       res = (n*res)%mod;
 
    return res;
}
ll fastExponentiation(ll n, ll x, ll modulo) 
{
    ll res = 1;
    while(x > 0) 
       {
          if(x & 1)
          res = (res*n) % modulo; 
          x = x >> 1;
          n = (n * n) % modulo;
       }
       return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n, a, ans = 0, i = 1, rem;
        cin>>n>>a;
        n = n*n;
        while(n > 0)
        {
            rem = 2*i - 1;
            ans = (ans + fastExponentiation(a, rem, mod))%mod;
            a = (a*fastExponentiation(a, rem, mod))%mod;
            n -= rem;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
