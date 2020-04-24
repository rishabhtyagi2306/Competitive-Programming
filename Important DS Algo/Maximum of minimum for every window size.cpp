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

void printMaxOfMin(int arr[], int n) 
{ 
    // Consider all windows of different sizes starting 
    // from size 1 
    for (int k=1; k<=n; k++) 
    { 
        // Initialize max of min for current window size k 
        int maxOfMin = INT_MIN; 
  
        // Traverse through all windows of current size k 
        for (int i = 0; i <= n-k; i++) 
        { 
            // Find minimum of current window 
            int min = arr[i]; 
            for (int j = 1; j < k; j++) 
            { 
                if (arr[i+j] < min) 
                    min = arr[i+j]; 
            } 
  
            // Update maxOfMin if required 
            if (min > maxOfMin) 
              maxOfMin = min; 
        } 
  
        // Print max of min for current window size 
        cout << maxOfMin << " "; 
    } 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[] = {10, 20, 30, 50, 10, 70, 30}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxOfMin(arr, n); 
    return 0;
}
